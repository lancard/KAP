#include "KAPScreen.h"

extern unordered_map<std::string, CPosition> runway_map;

CKAPScreen::CKAPScreen(CKAPChecker *plugin)
{
    this->KAPPlugin = plugin;
}

CKAPScreen::~CKAPScreen()
{
}

void CKAPScreen::OnAsrContentToBeClosed(void)
{
    delete this;
}

void CKAPScreen::OnRefresh(HDC hDC, int Phase)
{
    if (Phase != EuroScopePlugIn::REFRESH_PHASE_AFTER_TAGS)
        return;

    unordered_map<string, string> callsign_approach_runway_map;

    KAPPlugin->getApproachRunwayMapCopy(callsign_approach_runway_map);



    HPEN hPenOld;
    HPEN hLinePen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
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
