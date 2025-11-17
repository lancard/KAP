#include "KAPChecker.h"
#include "KAPFixes.h"
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")

#define RGB_YELLOW RGB(255, 255, 0)

std::string HttpGet(const std::string &url)
{
	int wlen = MultiByteToWideChar(CP_UTF8, 0, url.c_str(), -1, nullptr, 0);
	std::wstring wurl(wlen, 0);
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

	std::string response;
	DWORD sizeAvailable = 0;

	do
	{
		sizeAvailable = 0;
		if (!WinHttpQueryDataAvailable(hRequest, &sizeAvailable))
			break;
		if (sizeAvailable == 0)
			break;

		std::string buffer(sizeAvailable, 0);
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

CKAPChecker::CKAPChecker(void) : CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
										 "KAP",
										 "2.7",
										 "Sung-ho Kim",
										 "Sung-ho Kim")
{
	InitializeFixes();
	InitializeFirBoundaryFixes();

	RegisterTagItemType("RKRR_Checker", TAG_ITEM_RKRR);

	DisplayUserMessage("Message", "KAP", std::string("KAP Loaded.").c_str(), false, false, false, false, false);
}

CKAPChecker::~CKAPChecker(void)
{
	DisplayUserMessage("Message", "KAP", std::string("KAP Unloaded.").c_str(), false, false, false, false, false);
}

bool CKAPChecker::OnCompileCommand(const char *sCommandLine)
{
	DisplayUserMessage("ACARS", "ACARS", sCommandLine, true, true, false, false, false);
	return false;
}

void CKAPChecker::OnTimer(int Counter)
{
	char url[256];

	if (Counter % 30 == 0)
	{
		const char *LogonCode = this->GetDataFromSettings("LogonCode");
		if (LogonCode == nullptr) {
			DisplayUserMessage("ACARS", "SYSTEM", "Please type your hoppie's logon code to access.", true, true, false, false, false);
			return;
		}

		// prepare url
		snprintf(url, 255, "http://www.hoppie.nl/acars/system/connect.html?logon=%s&from=RKRR_A_CTR&to=RKRR_A_CTR&type=poll&packet=", LogonCode);

		std::string acars = HttpGet(url);
		DisplayUserMessage("ACARS", "ACARS", acars.c_str(), true, true, false, false, false);
		/*
		this->SaveDataToSettings("LogonCode",
								"Hoppie logon code for ACARS",
								"2.7");
		*/
	}

	// DisplayUserMessage("ACARS", "DEBUG", this->ControllerMyself().GetCallsign(), true, true, false, false, false);	
}

double CKAPChecker::calculateDistanceInNm(CRadarTarget RadarTarget, CPosition point)
{
	return RadarTarget.GetPosition().GetPosition().DistanceTo(point);
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

void CKAPChecker::OnGetTagItem(CFlightPlan FlightPlan, CRadarTarget RadarTarget, int ItemCode, int TagData,
							   char sItemString[16], int *pColorCode, COLORREF *pRGB, double *pFontSize)
{
	if (ItemCode != TAG_ITEM_RKRR)
		return;

	if (!FlightPlan.IsValid())
		return;

	if (!RadarTarget.IsValid())
		return;

	if (RadarTarget.GetGS() > 60 && !RadarTarget.GetPosition().GetTransponderC())
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SQ_C");
		return;
	}

	bool need_odd_level = false;
	bool need_even_level = false;

	string flight_rule = FlightPlan.GetFlightPlanData().GetPlanType();
	string origin_airport = FlightPlan.GetFlightPlanData().GetOrigin();
	string destination_airport = FlightPlan.GetFlightPlanData().GetDestination();
	// check destination airport starts with RK
	bool is_destination_rk = false;
	if (destination_airport.length() >= 2 && destination_airport.substr(0, 2) == "RK")
	{
		is_destination_rk = true;
	}
	string destination_rwy = FlightPlan.GetFlightPlanData().GetArrivalRwy();
	if (flight_rule == "I" && is_destination_rk && destination_rwy.empty())
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NO_RWY");
		return;
	}
	int altitude = RadarTarget.GetPosition().GetPressureAltitude();
	int final_altitude = FlightPlan.GetFlightPlanData().GetFinalAltitude();
	int temp_altitude = FlightPlan.GetControllerAssignedData().GetClearedAltitude();
	int temp_or_final_altitude = (temp_altitude <= 0 ? final_altitude : temp_altitude);
	bool cleared_approach = (temp_altitude == 1);
	bool cleared_visual_approach = (temp_altitude == 2);
	double heading = RadarTarget.GetTrackHeading();

	if (
		origin_airport == "RKSI" ||
		origin_airport == "RKSS" ||
		origin_airport == "RKTU" ||
		origin_airport == "RKSO" ||
		origin_airport == "RKSM")
	{
		if (
			destination_airport == "RKPC" ||
			destination_airport == "RKPD" ||
			destination_airport == "RKJB" ||
			destination_airport == "RKJY" ||
			destination_airport == "RKJJ")
		{
			need_even_level = true;
		}
		if (
			destination_airport == "RKPK" ||
			destination_airport == "RKTN" ||
			destination_airport == "RKTH" ||
			destination_airport == "RKTL" ||
			destination_airport == "RKNY")
		{
			need_odd_level = true;
		}
	}

	if (
		origin_airport == "RKPC" ||
		origin_airport == "RKPD" ||
		origin_airport == "RKJB" ||
		origin_airport == "RKJY" ||
		origin_airport == "RKJJ")
	{
		if (
			destination_airport == "RKSI" ||
			destination_airport == "RKSS" ||
			destination_airport == "RKTU" ||
			destination_airport == "RKSO" ||
			destination_airport == "RKSM" ||
			destination_airport == "RKPK" ||
			destination_airport == "RKTN" ||
			destination_airport == "RKTH" ||
			destination_airport == "RKTL" ||
			destination_airport == "RKNY")
		{
			need_odd_level = true;
		}
	}

	if (
		origin_airport == "RKPK" ||
		origin_airport == "RKTN" ||
		origin_airport == "RKTH" ||
		origin_airport == "RKTL" ||
		origin_airport == "RKNY")
	{
		if (
			destination_airport == "RKSI" ||
			destination_airport == "RKSS" ||
			destination_airport == "RKTU" ||
			destination_airport == "RKSO" ||
			destination_airport == "RKSM" ||
			destination_airport == "RKPC" ||
			destination_airport == "RKPD" ||
			destination_airport == "RKJB" ||
			destination_airport == "RKJY" ||
			destination_airport == "RKJJ")
		{
			need_even_level = true;
		}
	}

	if (need_even_level)
	{
		if (
			final_altitude == 5000 ||
			final_altitude == 7000 ||
			final_altitude == 9000 ||
			final_altitude == 11000 ||
			final_altitude == 13000 ||
			final_altitude == 15000 ||
			final_altitude == 17000 ||
			final_altitude == 19000 ||
			final_altitude == 21000 ||
			final_altitude == 23000 ||
			final_altitude == 25000 ||
			final_altitude == 27000 ||
			final_altitude == 29000 ||
			final_altitude == 31000 ||
			final_altitude == 33000 ||
			final_altitude == 35000 ||
			final_altitude == 37000 ||
			final_altitude == 39000)
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_EVEN_ALT");
			return;
		}
	}

	if (need_odd_level)
	{
		if (
			final_altitude == 4000 ||
			final_altitude == 6000 ||
			final_altitude == 8000 ||
			final_altitude == 10000 ||
			final_altitude == 12000 ||
			final_altitude == 14000 ||
			final_altitude == 16000 ||
			final_altitude == 18000 ||
			final_altitude == 20000 ||
			final_altitude == 22000 ||
			final_altitude == 24000 ||
			final_altitude == 26000 ||
			final_altitude == 28000 ||
			final_altitude == 30000 ||
			final_altitude == 32000 ||
			final_altitude == 34000 ||
			final_altitude == 36000 ||
			final_altitude == 38000)
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_ODD_ALT");
			return;
		}
	}

	if (FlightPlan.GetTrackingControllerIsMe())
	{
		// near AGAVO
		if (calculateDistanceInNm(RadarTarget, *AGAVO) < 40.0 && heading > 190.0 && heading < 350.0)
		{
			// RVSM(ft)
			if (final_altitude == 21700 || final_altitude == 23600 || final_altitude == 25600 || final_altitude == 27600 || final_altitude == 30100 || final_altitude == 32100 || final_altitude == 34100 || final_altitude == 36100 || final_altitude == 38100 || final_altitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (destination_airport == "ZSWH" || destination_airport == "ZSYT")
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (final_altitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (final_altitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (final_altitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (final_altitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (final_altitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (final_altitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (final_altitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (final_altitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (final_altitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (final_altitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near GOLOT
		if (calculateDistanceInNm(RadarTarget, *GOLOT) < 40.0 && heading > 270.0 && heading < 350.0)
		{
			// RVSM(ft)
			if (final_altitude == 21700 || final_altitude == 23600 || final_altitude == 25600 || final_altitude == 27600 || final_altitude == 30100 || final_altitude == 32100 || final_altitude == 34100 || final_altitude == 36100 || final_altitude == 38100 || final_altitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (destination_airport == "ZYTX")
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (final_altitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (final_altitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (final_altitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (final_altitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (final_altitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (final_altitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (final_altitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (final_altitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (final_altitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (final_altitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near TOMUK
		if (calculateDistanceInNm(RadarTarget, *TOMUK) < 40.0 && heading > 190.0 && heading < 350.0)
		{
			// RVSM(ft)
			if (final_altitude == 21700 || final_altitude == 23600 || final_altitude == 25600 || final_altitude == 27600 || final_altitude == 30100 || final_altitude == 32100 || final_altitude == 34100 || final_altitude == 36100 || final_altitude == 38100 || final_altitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (destination_airport == "ZYTL")
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (final_altitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (final_altitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (final_altitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (final_altitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (final_altitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (final_altitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (final_altitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (final_altitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (final_altitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (final_altitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near VASRO
		if (calculateDistanceInNm(RadarTarget, *VASRO) < 40.0 && heading > 270.0 && heading < 359.0)
		{
			// RVSM(ft)
			if (final_altitude == 21700 || final_altitude == 23600 || final_altitude == 25600 || final_altitude == 27600 || final_altitude == 30100 || final_altitude == 32100 || final_altitude == 34100 || final_altitude == 36100 || final_altitude == 38100 || final_altitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (final_altitude == 22000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL217/6600m");
					return;
				}
				if (final_altitude == 24000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL236/7200m");
					return;
				}
				if (final_altitude == 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL256/7800m");
					return;
				}
				if (final_altitude == 28000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL276/8400m");
					return;
				}
				if (final_altitude == 30000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL301/9200m");
					return;
				}
				if (final_altitude == 32000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL321/9800m");
					return;
				}
				if (final_altitude == 34000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL341/10400m");
					return;
				}
				if (final_altitude == 36000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL361/11000m");
					return;
				}
				if (final_altitude == 38000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL381/11600m");
					return;
				}
				if (final_altitude == 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL401/12200m");
					return;
				}
			}
		}

		// near LAMEN
		if (calculateDistanceInNm(RadarTarget, *LAMEN) < 40.0 && heading > 190.0 && heading < 350.0)
		{
			if (destination_airport == "ZSPD" ||
				destination_airport == "ZSSS" ||
				destination_airport == "ZSNB" ||
				destination_airport == "ZSWX" ||
				destination_airport == "ZSNJ" ||
				destination_airport == "ZSCG" ||
				destination_airport == "ZSNT" ||
				destination_airport == "ZSHC")
			{
				if (temp_or_final_altitude != 22000 && temp_or_final_altitude != 24000 && temp_or_final_altitude != 26000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL220/240/260");
					return;
				}
			}
			else
			{
				if (temp_or_final_altitude != 24000 && temp_or_final_altitude != 26000 && temp_or_final_altitude != 28000 && temp_or_final_altitude != 30000 &&
					temp_or_final_altitude != 32000 && temp_or_final_altitude != 34000 && temp_or_final_altitude != 36000 && temp_or_final_altitude != 38000 && temp_or_final_altitude != 40000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL240 or higher");
					return;
				}
			}
		}

		// near ADNUR
		if (calculateDistanceInNm(RadarTarget, *ADNUR) < 40.0 && heading < 90.0)
		{
			if (destination_airport == "UHWW")
			{
				if (temp_or_final_altitude != 25000 && temp_or_final_altitude != 23000 && temp_or_final_altitude != 21000 && temp_or_final_altitude != 19000 &&
					temp_or_final_altitude != 17000 && temp_or_final_altitude != 15000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250 or lower");
					return;
				}
			}
		}

		// near RIVAT
		if (calculateDistanceInNm(RadarTarget, *RIVAT) < 40.0 && (heading < 90.0 || heading > 330.0))
		{
			if (destination_airport == "UHWW")
			{
				if (temp_or_final_altitude != 25000 && temp_or_final_altitude != 23000 && temp_or_final_altitude != 21000 && temp_or_final_altitude != 19000 &&
					temp_or_final_altitude != 17000 && temp_or_final_altitude != 15000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250 or lower");
					return;
				}
			}
		}

		// near INVOK
		if (calculateDistanceInNm(RadarTarget, *INVOK) < 40.0 && heading > 90.0 && heading < 180.0)
		{
			if (destination_airport == "RJFF")
			{
				if (temp_or_final_altitude != 25000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250");
					return;
				}
			}
		}

		// near APELA
		if (calculateDistanceInNm(RadarTarget, *APELA) < 40.0 && heading > 90.0 && heading < 180.0)
		{
			if (destination_airport == "RJFF")
			{
				if (temp_or_final_altitude != 25000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250");
					return;
				}
			}
		}

		// near BESNA
		if (calculateDistanceInNm(RadarTarget, *BESNA) < 40.0 && heading > 90.0 && heading < 180.0)
		{
			if (destination_airport == "RJFF")
			{
				if (temp_or_final_altitude != 25000)
				{
					setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "FL250");
					return;
				}
			}
		}

		for (int a = 0; a < NUMBER_OF_FIR_BOUNDARY_FIX_LIST; a++)
		{
			double distance = calculateDistanceInNm(RadarTarget, fir_boundary_fix_list[a]);
			if (distance < 20)
			{
				setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
				return;
			}
		}
	}

	// show proper altitude (by 1nm = 300ft rule)
	double distance_to_destination = FlightPlan.GetDistanceToDestination();
	if (destination_airport[0] == 'R' && destination_airport[1] == 'K' && RadarTarget.GetGS() > 60)
	{
		double proper_altitude_by_100 = distance_to_destination * 3;
		double proper_altitude = distance_to_destination * 3 * 100;

		if (proper_altitude_by_100 < 0.0)
		{
			proper_altitude_by_100 = 0.0;
		}

		if (altitude > proper_altitude)
		{
			// need descent
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "DES:%.0f", proper_altitude_by_100);
			return;
		}

		// show proper altitude when approaching TD (top of descent)
		if (altitude * 1.5 > proper_altitude || distance_to_destination < 50.0)
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_DEFAULT, 0, "DES:%.0f", proper_altitude_by_100);
			return;
		}
	}
}

void CKAPChecker::OnFunctionCall(int FunctionId, const char *sItemString, POINT Pt, RECT Area)
{
}

void CKAPChecker::OnFlightPlanFlightPlanDataUpdate(CFlightPlan FlightPlan)
{
	if (!FlightPlan.IsValid())
		return;
}