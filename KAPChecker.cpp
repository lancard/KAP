#include "KAPChecker.h"
#include "KAPInfo.h"
#include "KAPFixes.h"

#define RGB_YELLOW RGB(255, 255, 0)

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

	RegisterTagItemType("RKRR_Checker", TAG_ITEM_KAP_RKRR);
	RegisterTagItemType("RKRR_Checker_Status", TAG_ITEM_KAP_STATUS);

	DisplayUserMessage("Message", "KAP", std::string("KAP Loaded.").c_str(), false, false, false, false, false);
}

CKAPChecker::~CKAPChecker(void)
{
	DisplayUserMessage("Message", "KAP", std::string("KAP Unloaded.").c_str(), false, false, false, false, false);
}

void CKAPChecker::OnTimer(int Counter)
{
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
	if (!FlightPlan.IsValid())
		return;

	if (!RadarTarget.IsValid())
		return;

	// set all info
	CKAPInfo kapinfo;
	kapinfo.Latitude = RadarTarget.GetPosition().GetPosition().m_Latitude;
	kapinfo.Longitude = RadarTarget.GetPosition().GetPosition().m_Longitude;
	kapinfo.Altitude = RadarTarget.GetPosition().GetPressureAltitude();
	kapinfo.TempAltitude = FlightPlan.GetControllerAssignedData().GetClearedAltitude();
	kapinfo.FinalAltitude = FlightPlan.GetFlightPlanData().GetFinalAltitude();
	kapinfo.Heading = RadarTarget.GetTrackHeading();
	kapinfo.GroundSpeed = RadarTarget.GetGS();
	kapinfo.DepartureAirport = FlightPlan.GetFlightPlanData().GetOrigin();
	kapinfo.DepartureRunway = FlightPlan.GetFlightPlanData().GetDepartureRwy();
	kapinfo.DestinationAirport = FlightPlan.GetFlightPlanData().GetDestination();
	kapinfo.DestinationRunway = FlightPlan.GetFlightPlanData().GetArrivalRwy();
	kapinfo.Route = FlightPlan.GetFlightPlanData().GetRoute();
	kapinfo.isVFR = (FlightPlan.GetFlightPlanData().GetPlanType() == "V");
	kapinfo.PlanSquawk = FlightPlan.GetControllerAssignedData().GetSquawk();
	kapinfo.CurrentSquawk = RadarTarget.GetPosition().GetSquawk();
	kapinfo.isSquawkModeC = RadarTarget.GetPosition().GetTransponderC();

	if (ItemCode == TAG_ITEM_KAP_STATUS)
	{
		string flightTypeString = kapinfo.GetTypeOfFlightString();
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", flightTypeString.c_str());
		return;
	}

	if (ItemCode != TAG_ITEM_KAP_RKRR)
		return;

	// ignore depature == arrival airport
	if (kapinfo.DepartureAirport == kapinfo.DestinationAirport)
	{
		return;
	}

	// check all! -----------------------------------------------------------------------------

	// sq mode check
	if (kapinfo.IsAirborne() && !kapinfo.isSquawkModeC)
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SQ_C");
		return;
	}

	// meter metric conversion check
	if (FlightPlan.GetTrackingControllerIsMe())
	{
		// near AGAVO
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["AGAVO"]) < 50.0 && kapinfo.IsWestBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["GOLOT"]) < 50.0 && kapinfo.IsWestBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["TOMUK"]) < 50.0 && kapinfo.IsWestBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["VASRO"]) < 50.0 && kapinfo.IsNorthBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["LAMEN"]) < 50.0 && kapinfo.IsWestBoundFlying())
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
				if (kapinfo.FinalAltitude != 22000 && kapinfo.FinalAltitude != 24000 && kapinfo.FinalAltitude != 26000)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["ADNUR"]) < 50.0 && kapinfo.IsNorthBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["RIVAT"]) < 50.0 && kapinfo.IsNorthBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["INVOK"]) < 50.0 && kapinfo.IsSouthBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["APELA"]) < 50.0 && kapinfo.IsSouthBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["BESNA"]) < 50.0 && kapinfo.IsSouthBoundFlying())
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["MUGUS"]) < 50.0 && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near ATOTI
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["ATOTI"]) < 50.0 && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near P2
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["P2"]) < 50.0 && kapinfo.IsNorthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near MESOV
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["MESOV"]) < 50.0 && kapinfo.IsNorthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near KANSU
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["KANSU"]) < 50.0 && kapinfo.IsNorthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near ANDOL
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["ANDOL"]) < 50.0 && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near IGRAS
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["IGRAS"]) < 50.0 && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near LANAT
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["LANAT"]) < 50.0 && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near SAPRA
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["SAPRA"]) < 50.0 && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near KALEK
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["KALEK"]) < 50.0 && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near SAMDO
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["SAMDO"]) < 50.0 && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near RUGMA
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["RUGMA"]) < 50.0 && kapinfo.IsSouthBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}

		// near BEDAR
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["BEDAR"]) < 50.0 && kapinfo.IsEastBoundFlying())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
			return;
		}
	}

	// end of hand-off checks ------------------------------

	// check even or odd level
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

	if (!kapinfo.isVFR && kapinfo.DestinationRunway.empty())
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NO_RWY");
		return;
	}

	// check restrictions by type
	int flightType = kapinfo.GetTypeOfFlight();

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
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SQ_NOT_EQ");
			return;
		}
	}

	if (flightType >= TAXI_TO_RUNWAY)
	{
		if (!kapinfo.IsSquawkCodeMatched())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SQ_NOT_EQ");
			return;
		}

		if (!kapinfo.isSquawkModeC)
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SQ_C");
			return;
		}
	}

	if (flightType == READY_FOR_DEP)
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "READY_DEP");
		return;
	}

	if (flightType == DEPARTED)
	{
	}

	if (flightType >= CRUSING)
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
			return;
		}
	}

	if (flightType == ARRIVAL)
	{
		if (kapinfo.Altitude < 10000 && !(kapinfo.IsClearedApproach() || kapinfo.IsClearedVisualApproach()))
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "CLRD_APPR");
			return;
		}
	}
}