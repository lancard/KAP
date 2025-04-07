#pragma once
#include <SDKDDKVer.h>
#include <afxwin.h>
#include <string>
#include "EuroScopePlugIn.h"

using namespace std;
using namespace EuroScopePlugIn;

class CKAPChecker :
	public EuroScopePlugIn::CPlugIn
{
public:
	CKAPChecker();
	~CKAPChecker();

	const int TAG_ITEM_RKRR = 7527;

	void OnGetTagItem(CFlightPlan FlightPlan, EuroScopePlugIn::CRadarTarget RadarTarget,
		int ItemCode,
		int TagData,
		char sItemString[16],
		int * pColorCode,
		COLORREF * pRGB,
		double * pFontSize);

	void OnFunctionCall(int FunctionId,
		const char * sItemString,
		POINT Pt,
		RECT Area);

	void setTag(char *target, int *targetColorCode, COLORREF *targetColor, int colorCode, COLORREF color, const char *format, ...);
	
	void OnFlightPlanFlightPlanDataUpdate(CFlightPlan FlightPlan);

	double calculateDistanceInNm(CRadarTarget RadarTarget, CPosition point);

	void OnTimer(int Counter);
};

