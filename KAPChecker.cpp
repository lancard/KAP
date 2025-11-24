#include "KAPChecker.h"
extern unordered_map<std::string, CPosition> fir_boundary_fix_map;
extern unordered_map<std::string, CPosition> fix_map;
extern unordered_map<std::string, CPosition> airport_map;
CPosition GetCPositionFromString(const string& latitude, const string& longitude);
void InitializeFirBoundaryFixes();
void InitializeFixes();
void InitializeAirports();
#include "KAPInfo.h"

#define RGB_YELLOW RGB(255, 255, 0)

CKAPChecker::CKAPChecker(void) : CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
										 "KAP",
										 PROGRAM_VERSION,
										 "Sung-ho Kim",
										 "Sung-ho Kim")
{
	InitializeFirBoundaryFixes();
	InitializeFixes();
	InitializeAirports();

	RegisterTagItemType("RKRR_Checker", TAG_ITEM_RKRR);

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
	if (ItemCode != TAG_ITEM_RKRR)
		return;

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
	kapinfo.isSquawkModeC = RadarTarget.GetPosition().GetTransponderC();

	string flightTypeString = kapinfo.GetTypeOfFlightString();
	setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", flightTypeString.c_str());
	return;

	// check all!
	if (kapinfo.IsAirborne() && !kapinfo.isSquawkModeC)
	{
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "SQ_C");
		return;
	}

	// ignore depature == arrival airport
	if (kapinfo.DepartureAirport == kapinfo.DestinationAirport)
	{
		return;
	}

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

	if (FlightPlan.GetTrackingControllerIsMe())
	{
		// near AGAVO
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["AGAVO"]) < 40.0 && kapinfo.Heading > 190.0 && kapinfo.Heading < 350.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["GOLOT"]) < 40.0 && kapinfo.Heading > 270.0 && kapinfo.Heading < 350.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["TOMUK"]) < 40.0 && kapinfo.Heading > 190.0 && kapinfo.Heading < 350.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["VASRO"]) < 40.0 && kapinfo.Heading > 270.0 && kapinfo.Heading < 359.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["LAMEN"]) < 40.0 && kapinfo.Heading > 190.0 && kapinfo.Heading < 350.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["ADNUR"]) < 40.0 && kapinfo.Heading < 90.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["RIVAT"]) < 40.0 && (kapinfo.Heading < 90.0 || kapinfo.Heading > 330.0))
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["INVOK"]) < 40.0 && kapinfo.Heading > 90.0 && kapinfo.Heading < 180.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["APELA"]) < 40.0 && kapinfo.Heading > 90.0 && kapinfo.Heading < 180.0)
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
		if (kapinfo.CalculateDistanceInNm(fir_boundary_fix_map["BESNA"]) < 40.0 && kapinfo.Heading > 90.0 && kapinfo.Heading < 180.0)
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

		// near FIR boundary - need hand-off
		for (const auto &[key, value] : fir_boundary_fix_map)
		{
			double distance = kapinfo.CalculateDistanceInNm(value);
			if (distance < 20)
			{
				setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", "NEED_HAND_OFF");
				return;
			}
		}
	}

	// show proper altitude (by 1nm = 300ft rule)
	double distance_to_destination = FlightPlan.GetDistanceToDestination();
	if (kapinfo.DestinationAirport[0] == 'R' && kapinfo.DestinationAirport[1] == 'K' && RadarTarget.GetGS() > 60)
	{
		double proper_altitude_by_100 = distance_to_destination * 3;
		double proper_altitude = distance_to_destination * 3 * 100;

		if (proper_altitude_by_100 < 0.0)
		{
			proper_altitude_by_100 = 0.0;
		}

		if (kapinfo.Altitude > proper_altitude)
		{
			// need descent
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "DES:%.0f", proper_altitude_by_100);
			return;
		}

		// show proper altitude when approaching TD (top of descent)
		if (kapinfo.Altitude * 1.5 > proper_altitude || distance_to_destination < 50.0)
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_DEFAULT, 0, "DES:%.0f", proper_altitude_by_100);
			return;
		}
	}
}