#include "KAPChecker.h"
#include "KAPInfo.h"
#include "KAPFixes.h"

#define RGB_YELLOW RGB(255, 255, 0)
#define RGB_BLUE RGB(0, 0, 255)

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
			if (kapinfo.Star.find("BITIM") != string::npos)
			{
				return "BITIM30";
			}

			return "MUNAN30";
		}
		if (kapinfo.DestinationRunway == "16L" || kapinfo.DestinationRunway == "16R")
		{
			if (kapinfo.Star.find("BITIM") != string::npos)
			{
				return "BITIM30";
			}

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
			if (kapinfo.Star.find("RNP") != string::npos)
			{
				return "NOORI40";
			}
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

	if (ItemCode == TAG_ITEM_KAP_STATUS)
	{
		string flightTypeString = kapinfo.GetTypeOfFlightString();
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_BLUE, "%s", flightTypeString.c_str());
		return;
	}

	if (ItemCode == TAG_ITEM_KAP_APP_ADVISORY)
	{
		string advisory = GetApproachAdvisory(kapinfo);
		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_DEFAULT, 0, "%s", advisory.c_str());
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

	if (!kapinfo.isVFR && kapinfo.IsDestinationRKRR() && kapinfo.DestinationRunway.empty())
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

	if (flightType == DEPARTURE_ROLLING)
	{
	}

	if (flightType == CLIMBING)
	{
	}

	if (flightType >= CRUISING)
	{
		double properAltitude = kapinfo.GetProperAltitudeForDestination();
		if (kapinfo.NeedExpeditedDescent())
		{
			setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "DES:%.0f", properAltitude / 100.0);
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

	if (flightType == TAXI_TO_GATE)
	{
	}

	if (flightType == PARKED_AT_GATE)
	{
	}

	// -- advisorys ----------------------------------------------------------------
	if (flightType >= CRUISING)
	{
		string advisory = "";

		// show IAF altitude
		if (kapinfo.NeedDescent())
		{
			// double to int conversion to avoid precision issue
			int properAltitude = (int)(kapinfo.GetProperAltitudeForDestination() / 100.0);
			advisory += "DES:" + to_string(properAltitude);
		}

		setTag(sItemString, pColorCode, pRGB, TAG_COLOR_RGB_DEFINED, RGB_YELLOW, "%s", advisory.c_str());
	}
}