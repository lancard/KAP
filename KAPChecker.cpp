#include "KAPChecker.h"
#include "KAPInfo.h"
#include "KAPFixes.h"
#include "KAPScreen.h"
#include "json.hpp"

#define RGB_RED RGB(255, 0, 0)
#define RGB_GREEN RGB(0, 255, 0)
#define RGB_BLUE RGB(0, 0, 255)
#define RGB_YELLOW RGB(255, 255, 0)
#define HANDOFF_DISTANCE_NM 25.0
#define FLIGHT_LEVEL_CHANGE_DISTANCE_NM 50.0

string HttpGet(const string &url)
{
	try
	{
		int wlen = MultiByteToWideChar(CP_UTF8, 0, url.c_str(), -1, nullptr, 0);
		wstring wurl(wlen, 0);
		MultiByteToWideChar(CP_UTF8, 0, url.c_str(), -1, &wurl[0], wlen);

		URL_COMPONENTS comp = {0};
		comp.dwStructSize = sizeof(comp);

		wchar_t host[256] = {};
		wchar_t path[2048] = {};
		comp.lpszHostName = host;
		comp.dwHostNameLength = 256;
		comp.lpszUrlPath = path;
		comp.dwUrlPathLength = 2048;

		if (!WinHttpCrackUrl(wurl.c_str(), 0, 0, &comp))
		{
			return "";
		}

		bool isHttps = (comp.nScheme == INTERNET_SCHEME_HTTPS);
		INTERNET_PORT port = comp.nPort;

		HINTERNET hSession = WinHttpOpen(L"HttpClient/1.0",
										 WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
										 WINHTTP_NO_PROXY_NAME,
										 WINHTTP_NO_PROXY_BYPASS, 0);

		if (!hSession)
			return "";

		HINTERNET hConnect = WinHttpConnect(hSession, comp.lpszHostName, port, 0);
		if (!hConnect)
		{
			WinHttpCloseHandle(hSession);
			return "";
		}

		HINTERNET hRequest = WinHttpOpenRequest(
			hConnect, L"GET", comp.lpszUrlPath,
			NULL, WINHTTP_NO_REFERER,
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			isHttps ? WINHTTP_FLAG_SECURE : 0);

		if (!hRequest)
		{
			WinHttpCloseHandle(hConnect);
			WinHttpCloseHandle(hSession);
			return "";
		}

		BOOL result = WinHttpSendRequest(
			hRequest,
			WINHTTP_NO_ADDITIONAL_HEADERS,
			0,
			WINHTTP_NO_REQUEST_DATA, 0,
			0, 0);

		if (!result)
		{
			WinHttpCloseHandle(hRequest);
			WinHttpCloseHandle(hConnect);
			WinHttpCloseHandle(hSession);
			return "";
		}

		result = WinHttpReceiveResponse(hRequest, NULL);
		if (!result)
		{
			WinHttpCloseHandle(hRequest);
			WinHttpCloseHandle(hConnect);
			WinHttpCloseHandle(hSession);
			return "";
		}

		string response;
		DWORD sizeAvailable = 0;

		do
		{
			sizeAvailable = 0;
			if (!WinHttpQueryDataAvailable(hRequest, &sizeAvailable))
				break;
			if (sizeAvailable == 0)
				break;

			string buffer(sizeAvailable, 0);
			DWORD bytesRead = 0;
			if (!WinHttpReadData(hRequest, &buffer[0], sizeAvailable, &bytesRead))
				break;

			response.append(buffer.c_str(), bytesRead);

		} while (sizeAvailable > 0);

		WinHttpCloseHandle(hRequest);
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);

		return response;
	}
	catch (...)
	{
		return "";
	}
}

std::string uppercase(std::string s)
{
	std::ranges::transform(s, s.begin(),
						   [](unsigned char c)
						   { return std::toupper(c); });
	return s;
}

string trim(const string &s)
{
	size_t start = 0;
	while (start < s.size() && isspace(static_cast<unsigned char>(s[start])))
	{
		++start;
	}

	if (start == s.size())
		return "";

	size_t end = s.size() - 1;
	while (end > start && isspace(static_cast<unsigned char>(s[end])))
	{
		--end;
	}

	return s.substr(start, end - start + 1);
}

CPosition GetCPositionFromString(const string &latitude, const string &longitude)
{
	CPosition pos;
	pos.LoadFromStrings(longitude.c_str(), latitude.c_str());
	return pos;
}

vector<string> split(const string &str, const string &delim)
{
	vector<string> result;
	size_t start = 0, pos;
	while ((pos = str.find(delim, start)) != string::npos)
	{
		result.push_back(str.substr(start, pos - start));
		start = pos + delim.size();
	}
	result.push_back(str.substr(start));
	return result;
}

string GetApproachAdvisory(CKAPInfo &kapinfo)
{
	if (kapinfo.DestinationAirport == "RKSI")
	{
		if (kapinfo.DestinationRunway == "15L" || kapinfo.DestinationRunway == "15R")
		{
			return "MUNAN30";
		}
		if (kapinfo.DestinationRunway == "16L" || kapinfo.DestinationRunway == "16R")
		{
			return "MUNAN20";
		}
		if (kapinfo.DestinationRunway == "33L" || kapinfo.DestinationRunway == "33R")
		{
			if (kapinfo.Star.find("PAMBI") != string::npos)
			{
				return "PAMBI36";
			}

			return "ENPIL70";
		}
		if (kapinfo.DestinationRunway == "34L" || kapinfo.DestinationRunway == "34R")
		{
			if (kapinfo.Star.find("PAMBI") != string::npos)
			{
				return "PAMBI26";
			}

			return "ENPIL70";
		}
	}

	if (kapinfo.DestinationAirport == "RKSS")
	{
		if (kapinfo.DestinationRunway == "14L" || kapinfo.DestinationRunway == "14R")
		{
			return "DOKDO40";
		}
		if (kapinfo.DestinationRunway == "32L" || kapinfo.DestinationRunway == "32R")
		{
			return "WONKO40";
		}
	}

	if (kapinfo.DestinationAirport == "RKPC")
	{
		if (kapinfo.DestinationRunway == "07")
		{
			return "YUMIN40";
		}
		if (kapinfo.DestinationRunway == "25")
		{
			return "DUKAL40";
		}
	}

	if (kapinfo.DestinationAirport == "RKPK")
	{
		if (kapinfo.DestinationRunway == "36L")
		{
			return "AKEVI33";
		}
		if (kapinfo.DestinationRunway == "36R")
		{
			return "BOSPI33";
		}
		if (kapinfo.DestinationRunway == "18L" || kapinfo.DestinationRunway == "18R")
		{
			return "OVLIN40";
		}
	}

	if (kapinfo.DestinationAirport == "RKTU")
	{
		if (kapinfo.DestinationRunway == "06L")
		{
			return "BAKJO44";
		}
		if (kapinfo.DestinationRunway == "24L")
		{
			return "IKAPO70";
		}
		if (kapinfo.DestinationRunway == "24R")
		{
			return "HYEIN60";
		}
	}

	if (kapinfo.DestinationAirport == "RKNY")
	{
		if (kapinfo.DestinationRunway == "33")
		{
			return "DUBUN60";
		}
	}

	if (kapinfo.DestinationAirport == "RKTN")
	{
		if (kapinfo.DestinationRunway == "13R")
		{
			return "YAWAN60";
		}
		if (kapinfo.DestinationRunway == "31L" || kapinfo.DestinationRunway == "31R")
		{
			return "UKBAT60";
		}
	}

	if (kapinfo.DestinationAirport == "RKJB")
	{
		if (kapinfo.DestinationRunway == "01")
		{
			if (kapinfo.Star.find("OVGEN") != string::npos)
			{
				return "OVGEN50";
			}
			if (kapinfo.Star.find("PEGRO") != string::npos)
			{
				return "PEGRO50";
			}
			return "OLBES60";
		}
		if (kapinfo.DestinationRunway == "19")
		{
			if (kapinfo.Star.find("DOWAN") != string::npos)
			{
				return "DOWAN50";
			}
			return "AYEON50";
		}
	}

	if (kapinfo.DestinationAirport == "RKJJ")
	{
		if (kapinfo.DestinationRunway == "04R")
		{
			return "KOTTY40";
		}
		if (kapinfo.DestinationRunway == "22L")
		{
			return "JADOO70";
		}
	}

	if (kapinfo.DestinationAirport == "RKJK")
	{
		if (kapinfo.DestinationRunway == "18")
		{
			return "BLAZZ30";
		}
		if (kapinfo.DestinationRunway == "36")
		{
			return "VIPIR30";
		}
	}

	if (kapinfo.DestinationAirport == "RKJY")
	{
		if (kapinfo.DestinationRunway == "17")
		{
			if (kapinfo.Star.find("YEONA") != string::npos)
			{
				return "YEONA50";
			}
			return "SKOTA50";
		}
		if (kapinfo.DestinationRunway == "35")
		{
			return "SOONA40";
		}
	}

	if (kapinfo.DestinationAirport == "RKNW")
	{
		if (kapinfo.DestinationRunway == "21")
		{
			return "VEMPU60";
		}
		if (kapinfo.DestinationRunway == "03")
		{
			return "ORINU50";
		}
	}

	if (kapinfo.DestinationAirport == "RKPS")
	{
		if (kapinfo.DestinationRunway == "06L" || kapinfo.DestinationRunway == "06R")
		{
			return "SOLYI60";
		}
		if (kapinfo.DestinationRunway == "24R" || kapinfo.DestinationRunway == "24L")
		{
			return "KABVO50";
		}
	}

	if (kapinfo.DestinationAirport == "RKPU")
	{
		if (kapinfo.DestinationRunway == "18")
		{
			return "MAKKY50";
		}
		if (kapinfo.DestinationRunway == "36")
		{
			return "HAEGU50";
		}
	}

	if (kapinfo.DestinationAirport == "RKSM")
	{
		if (kapinfo.DestinationRunway == "19" || kapinfo.DestinationRunway == "20")
		{
			return "Z-NITEX70/Y-BAVIX70";
		}
		if (kapinfo.DestinationRunway == "01")
		{
			return "UNTOM32";
		}
		if (kapinfo.DestinationRunway == "02")
		{
			return "SANIB32";
		}
	}

	if (kapinfo.DestinationAirport == "RKTH")
	{
		if (kapinfo.DestinationRunway == "10")
		{
			return "POSCO50";
		}
		if (kapinfo.DestinationRunway == "28")
		{
			return "SABUM30";
		}
	}

	if (kapinfo.DestinationAirport == "RKTL")
	{
		if (kapinfo.DestinationRunway == "17")
		{
			return "ALDON60";
		}
		if (kapinfo.DestinationRunway == "35")
		{
			return "BANYA60";
		}
	}

	if (kapinfo.DestinationAirport == "RKPD")
	{
		if (kapinfo.DestinationRunway == "01")
		{
			return "BIGTU38";
		}
	}

	if (kapinfo.DestinationAirport == "RKTA")
	{
		if (kapinfo.DestinationRunway == "15")
		{
			return "BACKA40";
		}
		if (kapinfo.DestinationRunway == "33")
		{
			return "KWANG40";
		}
	}

	if (kapinfo.DestinationAirport == "ZKPY")
	{
		if (kapinfo.DestinationRunway == "35")
		{
			return "PY42330";
		}
		if (kapinfo.DestinationRunway == "17")
		{
			return "PY43224";
		}
	}

	if (kapinfo.DestinationAirport == "ZKWS")
	{
		if (kapinfo.DestinationRunway == "15L")
		{
			return "KM41426";
		}
		if (kapinfo.DestinationRunway == "31L" || kapinfo.DestinationRunway == "31R")
		{
			return "KM50430";
		}
	}
	return "";
}

void InitializeFixes()
{
	for (const char *f : fix_list)
	{
		string fix = f;

		vector<string> fixParts = split(fix, ":");
		if (fixParts.size() < 4)
			continue;

		string fixType = fixParts[0];
		string fixName = fixParts[1];
		string fixLatitude = fixParts[2];
		string fixLongitude = fixParts[3];

		if (fixType == "FIR_BOUNDARY")
		{
			fir_boundary_fix_map[fixName] = GetCPositionFromString(fixLatitude, fixLongitude);
			continue;
		}
		if (fixType == "FIX")
		{
			fix_map[fixName] = GetCPositionFromString(fixLatitude, fixLongitude);
			continue;
		}
		if (fixType == "AIRPORT")
		{
			airport_map[fixName] = GetCPositionFromString(fixLatitude, fixLongitude);
			continue;
		}
		if (fixType == "RUNWAY")
		{
			runway_map[fixName] = GetCPositionFromString(fixLatitude, fixLongitude);
			runway_map[fixName + "-OPPOSITE"] = GetCPositionFromString(fixParts[4], fixParts[5]);
			continue;
		}
	}
}

CKAPChecker::CKAPChecker(void) : CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
										 "KAP",
										 PROGRAM_VERSION,
										 "Sung-ho Kim",
										 "Sung-ho Kim")
{
	InitializeFixes();

	RegisterTagItemType("Checker", TAG_ITEM_KAP_RKRR);
	RegisterTagItemType("Flight Status", TAG_ITEM_KAP_STATUS);
	RegisterTagItemType("Approach Advisory", TAG_ITEM_KAP_APP_ADVISORY);
	RegisterTagItemType("Pilot Frequency", TAG_ITEM_KAP_FREQUENCY);

	transceiverWorkerThread = thread(&CKAPChecker::GetTransceiverThreadRunner, this);

	DisplayUserMessage("Message", "KAP", std::string("KAP Loaded.").c_str(), false, false, false, false, false);
}

CKAPChecker::~CKAPChecker(void)
{
	terminateSignal = true;
	// join the thread
	if (transceiverWorkerThread.joinable())
	{
		transceiverWorkerThread.join();
	}
	DisplayUserMessage("Message", "KAP", std::string("KAP Unloaded.").c_str(), false, false, false, false, false);
}

void CKAPChecker::GetTransceiverThreadRunner()
{
	while (!terminateSignal.load())
	{
		try
		{
			nlohmann::json list = nlohmann::json::parse(HttpGet("https://data.vatsim.net/v3/transceivers-data.json"));

			unordered_map<string, string> tempMap;
			for (const auto &item : list)
			{
				if (item["transceivers"].empty())
					continue;

				string callsign = item["callsign"];
				int frequency = item["transceivers"][0]["frequency"];
				// convert 122800015 to 122.800
				string frequencyStr = to_string(frequency);
				if (frequencyStr.length() < 6)
					continue;

				string prefix = frequencyStr.substr(0, 3);
				string suffix = frequencyStr.substr(3, 3);
				frequencyStr = prefix + "." + suffix;
				tempMap[callsign] = frequencyStr;
			}

			lock_guard<mutex> lock(callsignFrequencyMapMutex);
			callsignFrequencyMap.swap(tempMap);
		}
		catch (...)
		{
		}

		for (int i = 0; i < 30 && !terminateSignal.load(); ++i)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}

void CKAPChecker::OnTimer(int Counter)
{
	if (Counter % 60 == 0)
	{
		clearApproachRunwayMap();
	}
}

CRadarScreen *CKAPChecker::OnRadarScreenCreated(const char *sDisplayName,
												bool NeedRadarContent,
												bool GeoReferenced,
												bool CanBeSaved,
												bool CanBeCreated)
{
	return new CKAPScreen(this);
}

void CKAPChecker::clearApproachRunwayMap()
{
	lock_guard<mutex> lock(callsignApproachRunwayMapMutex);
	callsignApproachRunwayMap.clear();
}

void CKAPChecker::setCallsignApproachRunwayMap(const string &callsign, const string &runway)
{
	lock_guard<mutex> lock(callsignApproachRunwayMapMutex);
	callsignApproachRunwayMap[callsign] = runway;
}

void CKAPChecker::getApproachRunwayMapCopy(unordered_map<string, string> &outputMap)
{
	lock_guard<mutex> lock(callsignApproachRunwayMapMutex);
	outputMap = callsignApproachRunwayMap;
}

void CKAPChecker::setTag(char *target, int *targetColorCode, COLORREF *targetColor, int colorCode, COLORREF color, const char *format, ...)
{
	if (colorCode != TAG_COLOR_DEFAULT)
	{
		*targetColorCode = colorCode;
		*targetColor = color;
	}

	va_list args;
	va_start(args, format);

	_vsnprintf_s(target, 16, 15, format, args);

	va_end(args);
}

string CKAPChecker::GetMyFrequency()
{
	double freq = ControllerMyself().GetPrimaryFrequency();

	// convert 122.800 to "122.800"
	string frequencyStr = to_string(static_cast<int>(freq * 1000));
	if (frequencyStr.length() < 6)
		return "UNKNOWN";
	string prefix = frequencyStr.substr(0, 3);
	string suffix = frequencyStr.substr(3, 3);
	frequencyStr = prefix + "." + suffix;
	return frequencyStr;
}

void CKAPChecker::OnGetTagItem(CFlightPlan FlightPlan, CRadarTarget RadarTarget, int ItemCode, int TagData,
							   char sItemString[16], int *pColorCode, COLORREF *pRGB, double *pFontSize)
{
	if (!FlightPlan.IsValid())
		return;

	if (!RadarTarget.IsValid())
		return;

	// set all info
	CKAPInfo kapinfo;
	kapinfo.Callsign = RadarTarget.GetCallsign();
	kapinfo.Latitude = RadarTarget.GetPosition().GetPosition().m_Latitude;
	kapinfo.Longitude = RadarTarget.GetPosition().GetPosition().m_Longitude;
	kapinfo.Altitude = RadarTarget.GetPosition().GetPressureAltitude();
	kapinfo.TempAltitude = FlightPlan.GetControllerAssignedData().GetClearedAltitude();
	kapinfo.FinalAltitude = FlightPlan.GetFlightPlanData().GetFinalAltitude();
	kapinfo.Heading = RadarTarget.GetTrackHeading();
	kapinfo.GroundSpeed = RadarTarget.GetGS();
	kapinfo.VerticalSpeed = RadarTarget.GetVerticalSpeed();
	kapinfo.DepartureAirport = FlightPlan.GetFlightPlanData().GetOrigin();
	kapinfo.DepartureRunway = FlightPlan.GetFlightPlanData().GetDepartureRwy();
	kapinfo.Sid = FlightPlan.GetFlightPlanData().GetSidName();
	kapinfo.DestinationAirport = FlightPlan.GetFlightPlanData().GetDestination();
	kapinfo.DestinationRunway = FlightPlan.GetFlightPlanData().GetArrivalRwy();
	kapinfo.Star = FlightPlan.GetFlightPlanData().GetStarName();
	kapinfo.Route = FlightPlan.GetFlightPlanData().GetRoute();
	kapinfo.isVFR = (FlightPlan.GetFlightPlanData().GetPlanType() == "V");
	kapinfo.PlanSquawk = FlightPlan.GetControllerAssignedData().GetSquawk();
	kapinfo.CurrentSquawk = RadarTarget.GetPosition().GetSquawk();
	kapinfo.isSquawkModeC = RadarTarget.GetPosition().GetTransponderC();
	kapinfo.ScratchPadString = FlightPlan.GetControllerAssignedData().GetScratchPadString();
	{
		lock_guard<mutex> lock(callsignFrequencyMapMutex);
		auto it = callsignFrequencyMap.find(kapinfo.Callsign);
		if (it != callsignFrequencyMap.end())
		{
			kapinfo.listenFrequency = it->second;
		}
		else
		{
			kapinfo.listenFrequency = "UNKNOWN";
		}
	}
	int flightType = kapinfo.GetTypeOfFlight();

	if (ItemCode == TAG_ITEM_KAP_STATUS)
	{
		string flightTypeString = kapinfo.GetTypeOfFlightString();
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_BLUE, "%s", flightTypeString.c_str());
		return;
	}

	if (ItemCode == TAG_ITEM_KAP_FREQUENCY)
	{
		if (GetMyFrequency() == kapinfo.listenFrequency)
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_DEFAULT, 0, "%s/%s", GetMyFrequency().c_str(), kapinfo.listenFrequency.c_str());
		}
		else
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_DEFAULT, 0, "%s", kapinfo.listenFrequency.c_str());
		}
		return;
	}

	if (ItemCode == TAG_ITEM_KAP_APP_ADVISORY)
	{
		if (flightType == CRUISING || flightType == ARRIVAL || flightType == APPROACHING)
		{
			if (!kapinfo.isCloserToDepartureThanArrival() && !kapinfo.IsClearedApproach() && !kapinfo.IsClearedVisualApproach())
			{
				string advisory = GetApproachAdvisory(kapinfo);
				setTag(sItemString, pColorCode, pRGB, TAG_COLOR_DEFAULT, 0, "%s", advisory.c_str());
			}
		}
		return;
	}

	if (ItemCode != TAG_ITEM_KAP_RKRR)
		return;

	// for runway incursion warning system ------------------------------------------------
	string incursionRunway = "";
	if (kapinfo.IsOnDepartureRunway() && !kapinfo.IsAirborne())
	{
		incursionRunway = kapinfo.DepartureAirport + "-" + kapinfo.DepartureRunway;
	}
	if (kapinfo.IsOnDestinationRunway() || flightType == LANDING_ROLLING)
	{
		incursionRunway = kapinfo.DestinationAirport + "-" + kapinfo.DestinationRunway;
	}
	if (flightType == APPROACHING && kapinfo.GetDistanceFromApproachRunwayInNm() < 6.0)
	{
		incursionRunway = kapinfo.DestinationAirport + "-" + kapinfo.DestinationRunway;
	}
	setCallsignApproachRunwayMap(kapinfo.Callsign, incursionRunway);

	// ignore depature == arrival airport
	if (kapinfo.DepartureAirport == kapinfo.DestinationAirport)
	{
		return;
	}

	// check all! -----------------------------------------------------------------------------

	// meter metric conversion check
	if (FlightPlan.GetTrackingControllerIsMe())
	{
		// near AGAVO
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["AGAVO"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsWestBoundFlying())
		{
			// RVSM(ft)
			if (kapinfo.FinalAltitude == 21700 || kapinfo.FinalAltitude == 23600 || kapinfo.FinalAltitude == 25600 || kapinfo.FinalAltitude == 27600 || kapinfo.FinalAltitude == 30100 || kapinfo.FinalAltitude == 32100 || kapinfo.FinalAltitude == 34100 || kapinfo.FinalAltitude == 36100 || kapinfo.FinalAltitude == 38100 || kapinfo.FinalAltitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (kapinfo.DestinationAirport == "ZSWH" || kapinfo.DestinationAirport == "ZSYT")
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (kapinfo.FinalAltitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (kapinfo.FinalAltitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (kapinfo.FinalAltitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (kapinfo.FinalAltitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (kapinfo.FinalAltitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (kapinfo.FinalAltitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (kapinfo.FinalAltitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (kapinfo.FinalAltitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (kapinfo.FinalAltitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (kapinfo.FinalAltitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near GOLOT
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["GOLOT"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsWestBoundFlying())
		{
			// RVSM(ft)
			if (kapinfo.FinalAltitude == 21700 || kapinfo.FinalAltitude == 23600 || kapinfo.FinalAltitude == 25600 || kapinfo.FinalAltitude == 27600 || kapinfo.FinalAltitude == 30100 || kapinfo.FinalAltitude == 32100 || kapinfo.FinalAltitude == 34100 || kapinfo.FinalAltitude == 36100 || kapinfo.FinalAltitude == 38100 || kapinfo.FinalAltitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (kapinfo.DestinationAirport == "ZYTX")
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (kapinfo.FinalAltitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (kapinfo.FinalAltitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (kapinfo.FinalAltitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (kapinfo.FinalAltitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (kapinfo.FinalAltitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (kapinfo.FinalAltitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (kapinfo.FinalAltitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (kapinfo.FinalAltitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (kapinfo.FinalAltitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (kapinfo.FinalAltitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near TOMUK
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["TOMUK"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsWestBoundFlying())
		{
			// RVSM(ft)
			if (kapinfo.FinalAltitude == 21700 || kapinfo.FinalAltitude == 23600 || kapinfo.FinalAltitude == 25600 || kapinfo.FinalAltitude == 27600 || kapinfo.FinalAltitude == 30100 || kapinfo.FinalAltitude == 32100 || kapinfo.FinalAltitude == 34100 || kapinfo.FinalAltitude == 36100 || kapinfo.FinalAltitude == 38100 || kapinfo.FinalAltitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (kapinfo.DestinationAirport == "ZYTL")
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (kapinfo.FinalAltitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (kapinfo.FinalAltitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (kapinfo.FinalAltitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (kapinfo.FinalAltitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (kapinfo.FinalAltitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (kapinfo.FinalAltitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (kapinfo.FinalAltitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (kapinfo.FinalAltitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (kapinfo.FinalAltitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (kapinfo.FinalAltitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near VASRO
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["VASRO"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsNorthBoundFlying())
		{
			// RVSM(ft)
			if (kapinfo.FinalAltitude == 21700 || kapinfo.FinalAltitude == 23600 || kapinfo.FinalAltitude == 25600 || kapinfo.FinalAltitude == 27600 || kapinfo.FinalAltitude == 30100 || kapinfo.FinalAltitude == 32100 || kapinfo.FinalAltitude == 34100 || kapinfo.FinalAltitude == 36100 || kapinfo.FinalAltitude == 38100 || kapinfo.FinalAltitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (kapinfo.FinalAltitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (kapinfo.FinalAltitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (kapinfo.FinalAltitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (kapinfo.FinalAltitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (kapinfo.FinalAltitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (kapinfo.FinalAltitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (kapinfo.FinalAltitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (kapinfo.FinalAltitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (kapinfo.FinalAltitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (kapinfo.FinalAltitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near LAMEN
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["LAMEN"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsWestBoundFlying())
		{
			if (kapinfo.DestinationAirport == "ZSPD" ||
				kapinfo.DestinationAirport == "ZSSS" ||
				kapinfo.DestinationAirport == "ZSNB" ||
				kapinfo.DestinationAirport == "ZSWX" ||
				kapinfo.DestinationAirport == "ZSNJ" ||
				kapinfo.DestinationAirport == "ZSCG" ||
				kapinfo.DestinationAirport == "ZSNT" ||
				kapinfo.DestinationAirport == "ZSHC")
			{
				if (kapinfo.FinalAltitude != 22000 && kapinfo.FinalAltitude != 24000 && kapinfo.FinalAltitude != 26000 &&
					kapinfo.TempAltitude != 22000 && kapinfo.TempAltitude != 24000 && kapinfo.TempAltitude != 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL220/240/260");
					return;
				}
			}
			else
			{
				if (kapinfo.FinalAltitude != 24000 && kapinfo.FinalAltitude != 26000 && kapinfo.FinalAltitude != 28000 && kapinfo.FinalAltitude != 30000 &&
					kapinfo.FinalAltitude != 32000 && kapinfo.FinalAltitude != 34000 && kapinfo.FinalAltitude != 36000 && kapinfo.FinalAltitude != 38000 && kapinfo.FinalAltitude != 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL240 or higher");
					return;
				}
			}
		}

		// near ADNUR
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["ADNUR"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsNorthBoundFlying())
		{
			if (kapinfo.DestinationAirport == "UHWW")
			{
				if (kapinfo.FinalAltitude != 25000 && kapinfo.FinalAltitude != 23000 && kapinfo.FinalAltitude != 21000 && kapinfo.FinalAltitude != 19000 &&
					kapinfo.FinalAltitude != 17000 && kapinfo.FinalAltitude != 15000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250 or lower");
					return;
				}
			}
		}

		// near RIVAT
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["RIVAT"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsNorthBoundFlying())
		{
			if (kapinfo.DestinationAirport == "UHWW")
			{
				if (kapinfo.FinalAltitude != 25000 && kapinfo.FinalAltitude != 23000 && kapinfo.FinalAltitude != 21000 && kapinfo.FinalAltitude != 19000 &&
					kapinfo.FinalAltitude != 17000 && kapinfo.FinalAltitude != 15000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250 or lower");
					return;
				}
			}
		}

		// near INVOK
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["INVOK"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsSouthBoundFlying())
		{
			if (kapinfo.DestinationAirport == "RJFF")
			{
				if (kapinfo.FinalAltitude != 25000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250");
					return;
				}
			}
		}

		// near APELA
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["APELA"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsSouthBoundFlying())
		{
			if (kapinfo.DestinationAirport == "RJFF")
			{
				if (kapinfo.FinalAltitude != 25000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250");
					return;
				}
			}
		}

		// near BESNA
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["BESNA"]) < FLIGHT_LEVEL_CHANGE_DISTANCE_NM && kapinfo.IsSouthBoundFlying())
		{
			if (kapinfo.DestinationAirport == "RJFF")
			{
				if (kapinfo.FinalAltitude != 25000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250");
					return;
				}
			}
		}

		// near MUGUS
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["MUGUS"]) < HANDOFF_DISTANCE_NM && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near ATOTI
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["ATOTI"]) < HANDOFF_DISTANCE_NM && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near P2
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["P2"]) < HANDOFF_DISTANCE_NM && kapinfo.IsNorthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near MESOV
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["MESOV"]) < HANDOFF_DISTANCE_NM && kapinfo.IsNorthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near KANSU
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["KANSU"]) < HANDOFF_DISTANCE_NM && kapinfo.IsNorthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near ANDOL
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["ANDOL"]) < HANDOFF_DISTANCE_NM && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near IGRAS
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["IGRAS"]) < HANDOFF_DISTANCE_NM && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near LANAT
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["LANAT"]) < HANDOFF_DISTANCE_NM && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near SAPRA
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["SAPRA"]) < HANDOFF_DISTANCE_NM && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near KALEK
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["KALEK"]) < HANDOFF_DISTANCE_NM && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near SAMDO
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["SAMDO"]) < HANDOFF_DISTANCE_NM && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near RUGMA
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["RUGMA"]) < HANDOFF_DISTANCE_NM && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near BEDAR
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["BEDAR"]) < HANDOFF_DISTANCE_NM && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}
	}

	// end of hand-off checks ------------------------------

	// pre check (high priority) ----------------------------------------------------
	if (kapinfo.CurrentSquawk == "7500")
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_RED, "%s", "HIJACK");
		return;
	}
	if (kapinfo.CurrentSquawk == "7600")
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_RED, "%s", "RADIO_FAIL");
		return;
	}
	if (kapinfo.CurrentSquawk == "7700")
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_RED, "%s", "EMERGENCY");
		return;
	}

	// flight type specific checks -------------------------------------------------
	if (flightType == CLEARANCE)
	{
		if (kapinfo.IsMoving())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SET_SQ");
			return;
		}
	}

	if (flightType == PUSHBACK)
	{
		if (!kapinfo.IsSquawkCodeMatched())
		{
			string sq = string("SQ:") + kapinfo.PlanSquawk;
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", sq.c_str());
			return;
		}
	}

	if (flightType >= TAXI_TO_RUNWAY)
	{
		if (!kapinfo.IsSquawkCodeMatched())
		{
			string sq = string("SQ:") + kapinfo.PlanSquawk;
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", sq.c_str());
			return;
		}

		if (!kapinfo.isSquawkModeC)
		{
			if (flightType < TAXI_TO_GATE)
			{
				setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SQ_C");
				return;
			}
		}
	}

	if (flightType == READY_FOR_DEP)
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "READY_DEP");
		return;
	}

	if (flightType == DEPARTURE_ROLLING)
	{
	}

	if (flightType == CLIMBING)
	{
		// check scratch pad is empty
		if (!kapinfo.ScratchPadString.empty())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "CLR_SCRATCH");
			return;
		}
	}

	if (flightType == ARRIVAL)
	{
		if (kapinfo.Altitude < 13000 && !(kapinfo.IsClearedApproach() || kapinfo.IsClearedVisualApproach()))
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "CLRD_APPR");
			return;
		}
	}

	if (flightType >= APPROACHING)
	{
		if (kapinfo.Altitude < 4000 && FlightPlan.GetTrackingControllerIsMe())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "CLRD_LAND");
			return;
		}
	}

	if (flightType == LANDING_ROLLING)
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SAY_TAXI");
		return;
	}

	if (flightType >= CRUISING)
	{
	}

	if (flightType == TAXI_TO_GATE)
	{
	}

	if (flightType == PARKED_AT_GATE)
	{
	}

	// -- advisories ----------------------------------------------------------------
	if (kapinfo.PlanSquawk == "2000" || kapinfo.PlanSquawk == "7000" || kapinfo.PlanSquawk == "0000" || kapinfo.PlanSquawk == "")
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "CHANGE_SQ");
		return;
	}
	if (kapinfo.isVFR && !kapinfo.PlanSquawk.starts_with("12"))
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SET_VFR_SQ");
		return;
	}
	if (!kapinfo.isVFR && kapinfo.PlanSquawk.starts_with("12"))
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SET_IFR_SQ");
		return;
	}

	if (kapinfo.IsWestBoundPlan() && kapinfo.IsFinalOddLevel())
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_EVEN_ALT");
		return;
	}

	if (kapinfo.IsEastBoundPlan() && kapinfo.IsFinalEvenLevel())
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_ODD_ALT");
		return;
	}

	if (!kapinfo.isVFR && kapinfo.IsDestinationRKRR() && kapinfo.DestinationRunway.empty())
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NO_RWY");
		return;
	}

	if (flightType >= CRUISING)
	{
		double properAltitude = kapinfo.GetProperAltitudeForDestination();

		if (kapinfo.NeedExpeditedDescent())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "DES:%.0f", properAltitude / 100.0);
			return;
		}

		if (kapinfo.NeedDescent())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_DEFAULT, 0, "DES:%.0f", properAltitude / 100.0);
		}
	}

	if (GetMyFrequency() == kapinfo.listenFrequency && !kapinfo.IsInRKRR())
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "HEAR_MY_FREQ");
		return;
	}
}