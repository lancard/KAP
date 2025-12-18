#pragma once
#define PROGRAM_VERSION "3.7.3"
#include <SDKDDKVer.h>
#include <afxwin.h>
#include <string>
#include <mutex>
#include <unordered_map>
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")
#include "EuroScopePlugIn.h"

using namespace std;
using namespace EuroScopePlugIn;

class CKAPChecker : public EuroScopePlugIn::CPlugIn
{
private:
	mutex callsignApproachRunwayMapMutex;
	unordered_map<string, string> callsignApproachRunwayMap;

	atomic<bool> terminateSignal{false};
	thread transceiverWorkerThread;
	mutex callsignFrequencyMapMutex;
	unordered_map<string, string> callsignFrequencyMap;
public:
	CKAPChecker();
	~CKAPChecker();

	const int TAG_ITEM_KAP_RKRR = 7527;
	const int TAG_ITEM_KAP_STATUS = 7528;
	const int TAG_ITEM_KAP_APP_ADVISORY = 7529;
	const int TAG_ITEM_KAP_FREQUENCY = 7530;

	void OnGetTagItem(CFlightPlan FlightPlan, EuroScopePlugIn::CRadarTarget RadarTarget,
					  int ItemCode,
					  int TagData,
					  char sItemString[16],
					  int *pColorCode,
					  COLORREF *pRGB,
					  double *pFontSize);

	void setTag(char *target, int *targetColorCode, COLORREF *targetColor, int colorCode, COLORREF color, const char *format, ...);

	void clearApproachRunwayMap();
	void setCallsignApproachRunwayMap(const string& callsign, const string& runway);
	void getApproachRunwayMapCopy(unordered_map<string, string>& outputMap);

	CRadarScreen *OnRadarScreenCreated(const char *sDisplayName,
									   bool NeedRadarContent,
									   bool GeoReferenced,
									   bool CanBeSaved,
									   bool CanBeCreated);

	void OnTimer(int Counter);

	void GetTransceiverThreadRunner();

	string GetMyFrequency();
};
