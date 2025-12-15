#pragma once

#include "KAPChecker.h"

class CKAPScreen : public CRadarScreen
{
private:
    CKAPChecker *KAPPlugin;

public:
    CKAPScreen(CKAPChecker *plugin);
    virtual ~CKAPScreen();

    virtual void OnAsrContentToBeClosed(void);
    virtual void OnRefresh(HDC hDC, int Phase);
};