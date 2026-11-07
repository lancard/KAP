#pragma once

#include "KAPChecker.h"

class CKAPScreen : public CRadarScreen
{
private:
    HFONT m_font = nullptr;
    CKAPChecker *KAPPlugin;
    bool m_panelMoved = false;
    POINT m_panelPos = {0, 0};

    std::vector<std::string> m_lineCallsigns;   // 마지막으로 그린 줄 순서의 콜사인
    int m_lineH = 0;
    int m_listTop = 0;                          // 첫 줄의 top 좌표
    
public:
    CKAPScreen(CKAPChecker *plugin);
    virtual ~CKAPScreen();

    virtual void OnAsrContentToBeClosed(void);
    virtual void OnRefresh(HDC hDC, int Phase);
    virtual void OnDoubleClickScreenObject(int ObjectType, const char *sObjectId, POINT Pt, RECT Area, int Button);
    virtual void OnMoveScreenObject(int ObjectType, const char *sObjectId,
                                    POINT Pt, RECT Area, bool Released);
    void DrawATC(HDC hDC);
    void DrawOccupiedRunways(HDC hDC);
};