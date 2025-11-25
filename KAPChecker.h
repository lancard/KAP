#pragma once
#define PROGRAM_VERSION "3.0.2"
#include <SDKDDKVer.h>
#include <afxwin.h>
#include <string>
#include <unordered_map>
#include "EuroScopePlugIn.h"

using namespace std;
using namespace EuroScopePlugIn;

class CKAPChecker : public EuroScopePlugIn::CPlugIn
{
public:
	CKAPChecker();
	~CKAPChecker();

	const int TAG_ITEM_KAP_RKRR = 7527;
	const int TAG_ITEM_KAP_STATUS = 7528;

	void OnGetTagItem(CFlightPlan FlightPlan, EuroScopePlugIn::CRadarTarget RadarTarget,
					  int ItemCode,
					  int TagData,
					  char sItemString[16],
					  int *pColorCode,
					  COLORREF *pRGB,
					  double *pFontSize);

	void setTag(char *target, int *targetColorCode, COLORREF *targetColor, int colorCode, COLORREF color, const char *format, ...);

	void OnTimer(int Counter);
};
