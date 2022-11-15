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

	void OnFlightPlanFlightPlanDataUpdate(CFlightPlan FlightPlan);

	void OnTimer(int Counter);
};

