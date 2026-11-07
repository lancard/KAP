#include "KAPScreen.h"

#define OBJ_PANEL 17777

extern unordered_map<std::string, CPosition> runway_map;
extern unordered_map<string, vector<int>> callsignFrequencyMap; // kHz
extern std::mutex callsignFrequencyMapMutex;

string KHzToString(int khz);

CKAPScreen::CKAPScreen(CKAPChecker *plugin)
{
    this->KAPPlugin = plugin;

    // -11: 작은 글씨 (더 작게는 -10, 더 크게는 -12)
    m_font = CreateFontA(-11, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                         DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                         DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, "Consolas");
}

CKAPScreen::~CKAPScreen()
{
    if (m_font)
        DeleteObject(m_font);
}

void CKAPScreen::OnAsrContentToBeClosed(void)
{
    delete this;
}

namespace
{
    struct ControllerEntry
    {
        std::string callsign;
        std::string text; // "ID-콜사인(주파수) - 성명"
        int rank;         // 국가: 0 RK, 1 ZK, 2 기타
        int typeRank;     // 시설: 0 CTR, 1 APP, 2 TWR, 3 GND, 4 DEL, 5 기타
        bool isObs;
    };

    int CallsignRank(const std::string &cs)
    {
        if (cs.rfind("RK", 0) == 0)
            return 0;
        if (cs.rfind("ZK", 0) == 0)
            return 1;
        return 2;
    }

    // 콜사인 마지막 '_' 뒤의 접미사로 시설 종류 판별
    std::string CallsignSuffix(const std::string &cs)
    {
        size_t pos = cs.find_last_of('_');
        return (pos == std::string::npos) ? "" : cs.substr(pos + 1);
    }

    int TypeRank(const std::string &suffix)
    {
        if (suffix == "CTR")
            return 0;
        if (suffix == "APP" || suffix == "DEP")
            return 1;
        if (suffix == "TWR")
            return 2;
        if (suffix == "GND")
            return 3;
        if (suffix == "DEL")
            return 4;
        if (suffix == "ATIS")
            return 5;
        return 6;
    }
}

static std::vector<ControllerEntry> CollectControllers(CKAPChecker *plugin)
{
    std::vector<ControllerEntry> list;

    // 맵을 한 번만 복사 (락은 여기서만)
    unordered_map<string, vector<int>> freqMap;
    {
        std::lock_guard<std::mutex> lock(callsignFrequencyMapMutex);
        freqMap = callsignFrequencyMap;
    }

    for (EuroScopePlugIn::CController c = plugin->ControllerSelectFirst();
         c.IsValid();
         c = plugin->ControllerSelectNext(c))
    {
        // 옵저버도 포함해야 하므로 IsController() 필터는 제거
        std::string callsign = c.GetCallsign();
        std::string id = c.GetPositionId();
        std::string suffix = CallsignSuffix(callsign);

        int primKHz = (int)std::lround(c.GetPrimaryFrequency() * 1000.0);

        // 듣고 있는 주파수들 (prim 제외)
        std::string monitoring;
        auto it = freqMap.find(callsign);
        if (it != freqMap.end())
        {
            for (int khz : it->second)
            {
                if (khz == primKHz)
                    continue;
                if (!monitoring.empty())
                    monitoring += ",";
                monitoring += KHzToString(khz);
            }
        }

        char buf[256];
        if (monitoring.empty())
            snprintf(buf, sizeof(buf), "%3s %.3f %s - %s",
                     id.c_str(), c.GetPrimaryFrequency(), callsign.c_str(),
                     c.GetFullName());
        else
            snprintf(buf, sizeof(buf), "%3s %.3f %s (M: %s) - %s",
                     id.c_str(), c.GetPrimaryFrequency(), callsign.c_str(),
                     monitoring.c_str(), c.GetFullName());

        ControllerEntry e;
        e.callsign = callsign;
        e.text = buf;
        e.rank = CallsignRank(callsign);
        e.typeRank = TypeRank(suffix);
        e.isObs = (suffix == "OBS");
        list.push_back(e);
    }

    std::sort(list.begin(), list.end(),
              [](const ControllerEntry &a, const ControllerEntry &b)
              {
                  if (a.isObs != b.isObs)
                      return !a.isObs; // OBS는 항상 맨 뒤
                  if (a.rank != b.rank)
                      return a.rank < b.rank; // RK -> ZK -> 기타
                  if (a.typeRank != b.typeRank)
                      return a.typeRank < b.typeRank; // CTR -> APP -> TWR -> GND -> DEL
                  return a.callsign < b.callsign;
              });

    return list;
}

void CKAPScreen::OnMoveScreenObject(int ObjectType, const char *sObjectId,
                                    POINT Pt, RECT Area, bool Released)
{
    if (ObjectType == OBJ_PANEL)
    {
        m_panelPos.x = Area.left;
        m_panelPos.y = Area.top;
        m_panelMoved = true;
        RequestRefresh();
    }
}

void CKAPScreen::DrawATC(HDC hDC)
{
    std::vector<ControllerEntry> controllers = CollectControllers(KAPPlugin);

    // 기존 상태 저장 + 고정 폰트 선택 (GetTextMetrics보다 먼저)
    int oldBkMode = SetBkMode(hDC, TRANSPARENT);
    COLORREF oldColor = GetTextColor(hDC);
    HFONT oldFont = (HFONT)SelectObject(hDC, m_font);

    TEXTMETRIC tm;
    GetTextMetrics(hDC, &tm);
    const int lineH = tm.tmHeight;

    // 컨트롤러가 없으면 "no ATC" 한 줄 표시
    const char *noAtcText = "no ATC";
    const bool empty = controllers.empty();

    // 가장 긴 텍스트 폭 계산
    int maxW = 0;
    if (empty)
    {
        SIZE sz;
        GetTextExtentPoint32A(hDC, noAtcText, (int)strlen(noAtcText), &sz);
        maxW = sz.cx;
    }
    else
    {
        for (const auto &e : controllers)
        {
            SIZE sz;
            GetTextExtentPoint32A(hDC, e.text.c_str(), (int)e.text.size(), &sz);
            if (sz.cx > maxW)
                maxW = sz.cx;
        }
    }

    int panelW = maxW;
    int panelH = (empty ? 1 : (int)controllers.size()) * lineH;

    // 위치: 처음엔 우측 상단, 드래그 후에는 저장된 좌표 사용
    RECT panel;
    if (!m_panelMoved)
    {
        RECT radar = GetRadarArea();
        panel.right = radar.right;
        panel.left = panel.right - panelW;
        panel.top = radar.top;
        panel.bottom = panel.top + panelH;
    }
    else
    {
        panel.left = m_panelPos.x;
        panel.top = m_panelPos.y;
        panel.right = panel.left + panelW;
        panel.bottom = panel.top + panelH;
    }

    // 더블클릭 줄 판정용 (마지막으로 그린 상태 저장)
    m_lineH = lineH;
    m_listTop = panel.top;
    m_lineCallsigns.clear();
    if (!empty)
        for (const auto &e : controllers)
            m_lineCallsigns.push_back(e.callsign);

    // 배경 + 외곽선 (컨트롤러가 없어도 항상 표시)
    HBRUSH bg = CreateSolidBrush(RGB(40, 40, 40));
    FillRect(hDC, &panel, bg);
    DeleteObject(bg);
    AddScreenObject(OBJ_PANEL, "ATC_PANEL", panel, true, "Drag me");

    if (empty)
    {
        SetTextColor(hDC, RGB(220, 220, 220));
        RECT line = {panel.left, panel.top, panel.right, panel.top + lineH};
        DrawTextA(hDC, noAtcText, -1, &line,
                  DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX);
    }
    else
    {
        int y = panel.top;
        for (const auto &e : controllers)
        {
            COLORREF color = e.isObs         ? RGB(140, 140, 140)  // OBS
                             : (e.typeRank == 5) ? RGB(130, 150, 170)  // ATIS
                             : (e.rank == 0) ? RGB(255, 215, 0)    // RK
                             : (e.rank == 1) ? RGB(160, 255, 160)  // ZK
                                             : RGB(220, 220, 220); // 기타
            SetTextColor(hDC, color);

            RECT line = {panel.left, y, panel.right, y + lineH};
            DrawTextA(hDC, e.text.c_str(), -1, &line,
                      DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX);
            y += lineH;
        }
    }

    // 복원 (폰트는 처음 hDC에 선택돼 있던 것으로)
    SelectObject(hDC, oldFont);
    SetTextColor(hDC, oldColor);
    SetBkMode(hDC, oldBkMode);
}

void CKAPScreen::DrawOccupiedRunways(HDC hDC)
{
    unordered_map<string, string> callsign_approach_runway_map;

    KAPPlugin->getApproachRunwayMapCopy(callsign_approach_runway_map);

    HPEN hPenOld;
    HPEN hLinePen = CreatePen(PS_DOT, 1, RGB(255, 255, 0));
    hPenOld = (HPEN)SelectObject(hDC, hLinePen);

    for (const auto &[callsign, runway] : callsign_approach_runway_map)
    {
        if (runway.empty())
            continue;

        if (runway_map.find(runway) == runway_map.end() || runway_map.find(runway + "-OPPOSITE") == runway_map.end())
            continue;

        POINT point1 = ConvertCoordFromPositionToPixel(runway_map[runway]);
        POINT point2 = ConvertCoordFromPositionToPixel(runway_map[runway + "-OPPOSITE"]);

        // draw line for approach runway
        MoveToEx(hDC, point1.x, point1.y, NULL);
        LineTo(hDC, point2.x, point2.y);
    }

    SelectObject(hDC, hPenOld);
    DeleteObject(hLinePen);
}

void CKAPScreen::OnRefresh(HDC hDC, int Phase)
{
    if (Phase != EuroScopePlugIn::REFRESH_PHASE_AFTER_TAGS)
        return;

    DrawATC(hDC);
    DrawOccupiedRunways(hDC);
}

void CKAPScreen::OnDoubleClickScreenObject(int ObjectType, const char *sObjectId,
                                           POINT Pt, RECT Area, int Button)
{
    if (ObjectType != OBJ_PANEL)
        return;
    if (m_lineH <= 0 || Pt.y < m_listTop)
        return;

    int idx = (Pt.y - m_listTop) / m_lineH;
    if (idx < 0 || idx >= (int)m_lineCallsigns.size())
        return;

    const std::string &callsign = m_lineCallsigns[idx];

    KAPPlugin->DisplayUserMessage(callsign.c_str(), "SYSTEM", "(Type here)",
                                  true, true, true, false, false);
}