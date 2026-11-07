#pragma once

#include "KAPChecker.h"

class CKAPScreen : public CRadarScreen
{
private:
    HFONT m_font = nullptr;
    CKAPChecker *KAPPlugin;
    bool m_panelMoved = false;
    POINT m_panelPos = {0, 0};

public:
    CKAPScreen(CKAPChecker *plugin);
    virtual ~CKAPScreen();

    virtual void OnAsrContentToBeClosed(void);
    virtual void OnRefresh(HDC hDC, int Phase);
    virtual void OnMoveScreenObject(int ObjectType, const char *sObjectId,
                                    POINT Pt, RECT Area, bool Released);
};