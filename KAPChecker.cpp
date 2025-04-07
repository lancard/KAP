#include "KAPChecker.h"

#define RGB_YELLOW     RGB(255, 255, 0)


// FIR count
#define NUMBER_OF_FIX_LIST 18
CPosition fir_boundary_fix_list[NUMBER_OF_FIX_LIST];
CKAPChecker::CKAPChecker(void) :CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
	"KAP",
	"2.3",
	"Sung-ho Kim",
	"Sung-ho Kim")
{

	// AGAVO
	fir_boundary_fix_list[0].m_Latitude = 37.166666666666664;
	fir_boundary_fix_list[0].m_Longitude = 124;

	// LAMEN
	fir_boundary_fix_list[1].m_Latitude = 31.609954166666668;
	fir_boundary_fix_list[1].m_Longitude = 124;

	// ANDOL
	fir_boundary_fix_list[2].m_Latitude = 37.66611111111111;
	fir_boundary_fix_list[2].m_Longitude = 133;

	// APELA
	fir_boundary_fix_list[3].m_Latitude = 34.723055;
	fir_boundary_fix_list[3].m_Longitude = 129.23333305555556;

	// ATOTI
	fir_boundary_fix_list[4].m_Latitude = 30.00355777777778;
	fir_boundary_fix_list[4].m_Longitude = 125.19815694444445;

	// BESNA
	fir_boundary_fix_list[5].m_Latitude = 34.62166666666667;
	fir_boundary_fix_list[5].m_Longitude = 129.13083333333333;

	// IGRAS
	fir_boundary_fix_list[6].m_Latitude = 37.31257611111111;
	fir_boundary_fix_list[6].m_Longitude = 132.7362372222222;

	// INVOK
	fir_boundary_fix_list[7].m_Latitude = 34.78860944444445;
	fir_boundary_fix_list[7].m_Longitude = 129.32296944444445;

	// KALEK
	fir_boundary_fix_list[8].m_Latitude = 35.208888611111114;
	fir_boundary_fix_list[8].m_Longitude = 129.88472222222222;

	// KANSU
	fir_boundary_fix_list[9].m_Latitude = 38.63333333333333;
	fir_boundary_fix_list[9].m_Longitude = 132.475;

	// LANAT
	fir_boundary_fix_list[10].m_Latitude = 36.373237499999995;
	fir_boundary_fix_list[10].m_Longitude = 131.4283172222222;

	// MESOV
	fir_boundary_fix_list[11].m_Latitude = 38.63333333333333;
	fir_boundary_fix_list[11].m_Longitude = 130.46666666666667;

	// MUGUS
	fir_boundary_fix_list[12].m_Latitude = 30.001666666666665;
	fir_boundary_fix_list[12].m_Longitude = 124.95333333333333;

	// ONIKU
	fir_boundary_fix_list[13].m_Latitude = 32.194934999999994;
	fir_boundary_fix_list[13].m_Longitude = 126.65470444444445;

	// RUGMA
	fir_boundary_fix_list[14].m_Latitude = 32.503340277777774;
	fir_boundary_fix_list[14].m_Longitude = 126.96472416666667;

	// SAMDO
	fir_boundary_fix_list[15].m_Latitude = 33.58414916666667;
	fir_boundary_fix_list[15].m_Longitude = 128.3157688888889;

	// SAPRA
	fir_boundary_fix_list[16].m_Latitude = 35.823835;
	fir_boundary_fix_list[16].m_Longitude = 130.72357583333334;

	// BEDAR
	fir_boundary_fix_list[17].m_Latitude = 31.900277777777777;
	fir_boundary_fix_list[17].m_Longitude = 126.48611111111111;

	RegisterTagItemType("RKRR_Checker", TAG_ITEM_RKRR);
}

CKAPChecker::~CKAPChecker(void)
{
}

void CKAPChecker::OnGetTagItem(CFlightPlan FlightPlan, CRadarTarget RadarTarget, int ItemCode, int TagData, 
	char sItemString[16], int * pColorCode, COLORREF * pRGB, double * pFontSize)
{
	if (ItemCode != TAG_ITEM_RKRR)
		return;

	if (!FlightPlan.IsValid())
		return;

	if (!RadarTarget.IsValid())
		return;



	if (RadarTarget.GetGS() > 60 && !RadarTarget.GetPosition().GetTransponderC()) {
		_snprintf_s(sItemString, 16, 15, "%s", "SQ_C");
		*pColorCode = TAG_COLOR_RGB_DEFINED;
		*pRGB = RGB_YELLOW;
		return;
	}

	bool need_odd_level = false;
	bool need_even_level = false;

	string origin_airport = FlightPlan.GetFlightPlanData().GetOrigin();
	string destination_airport = FlightPlan.GetFlightPlanData().GetDestination();
	int final_altitude = FlightPlan.GetFlightPlanData().GetFinalAltitude();

	if (
		origin_airport == "RKSI" ||
		origin_airport == "RKSS" ||
		origin_airport == "RKTU" ||
		origin_airport == "RKSO" ||
		origin_airport == "RKSM"
		)
	{
		if (
			destination_airport == "RKPC" ||
			destination_airport == "RKPD" ||
			destination_airport == "RKJB" ||
			destination_airport == "RKJY" ||
			destination_airport == "RKJJ"
			)
		{
			need_even_level = true;
		}
		if (
			destination_airport == "RKPK" ||
			destination_airport == "RKTN" ||
			destination_airport == "RKTH" ||
			destination_airport == "RKTL" ||
			destination_airport == "RKNY"
			)
		{
			need_odd_level = true;
		}
	}



	if (
		origin_airport == "RKPC" ||
		origin_airport == "RKPD" ||
		origin_airport == "RKJB" ||
		origin_airport == "RKJY" ||
		origin_airport == "RKJJ"
		)
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
			destination_airport == "RKNY"
			)
		{
			need_odd_level = true;
		}
	}



	if (
		origin_airport == "RKPK" ||
		origin_airport == "RKTN" ||
		origin_airport == "RKTH" ||
		origin_airport == "RKTL" ||
		origin_airport == "RKNY"
		)
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
			destination_airport == "RKJJ"
			)
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
			final_altitude == 39000
			)
		{
			_snprintf_s(sItemString, 16, 15, "%s", "NEED_EVEN_ALT");
			*pColorCode = TAG_COLOR_RGB_DEFINED;
			*pRGB = RGB_YELLOW;
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
			final_altitude == 38000
			)
		{
			_snprintf_s(sItemString, 16, 15, "%s", "NEED_ODD_ALT");
			*pColorCode = TAG_COLOR_RGB_DEFINED;
			*pRGB = RGB_YELLOW;
			return;
		}

	}

	if (FlightPlan.GetTrackingControllerIsMe())
	{
		// check hand off (china)
		if (RadarTarget.GetPosition().GetPosition().m_Longitude>123.5 && RadarTarget.GetPosition().GetPosition().m_Longitude<125)
		{
			// RVSM(ft)
			if (final_altitude == 23600 || final_altitude == 25600 || final_altitude == 27600 || final_altitude == 30100 || final_altitude == 32100 || final_altitude == 34100 || final_altitude == 36100 || final_altitude == 38100 || final_altitude == 40100)
			{
				// this is correct.
			}
			else
			{
				if (final_altitude == 24000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL236/7200m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 26000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL256/7800m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 28000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL276/8400m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 30000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL301/9200m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 32000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL321/9800m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 34000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL341/10400m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 36000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL361/11000m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 38000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL381/11600m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
				if (final_altitude == 40000){
					_snprintf_s(sItemString, 16, 15, "%s", "FL401/12200m");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
			}
		}

	
		if (destination_airport[0] == 'R' && destination_airport[1] == 'K') {
			for (int a = 0; a < NUMBER_OF_FIX_LIST; a++){
				double distance = RadarTarget.GetPosition().GetPosition().DistanceTo(fir_boundary_fix_list[a]);
				if (distance < 20) {
					_snprintf_s(sItemString, 16, 15, "NEED_HAND_OFF");
					*pColorCode = TAG_COLOR_RGB_DEFINED;
					*pRGB = RGB_YELLOW;
					return;
				}
			}
		}
	}


	// show proper altitude (by 1nm = 300ft rule)
	if (destination_airport[0] == 'R' && destination_airport[1] == 'K' && RadarTarget.GetGS() > 60)
	{
		double proper_altitude_by_100 = FlightPlan.GetDistanceToDestination() * 3;
		double proper_altitude = FlightPlan.GetDistanceToDestination() * 3 * 100;

		if (RadarTarget.GetPosition().GetPressureAltitude() > proper_altitude) // standard pressure: param.RadarTarget.Position.FlightLevel
		{
			// need descent
			_snprintf_s(sItemString, 16, 15, "DES:%.0f", proper_altitude_by_100);
			*pColorCode = TAG_COLOR_RGB_DEFINED;
			*pRGB = RGB_YELLOW;
			return;
		}

		// show proper altitude when approaching TD (top of descent)
		if (RadarTarget.GetPosition().GetPressureAltitude() * 1.5 > proper_altitude || FlightPlan.GetDistanceToDestination() < 50)
		{
			_snprintf_s(sItemString, 16, 15, "DES:%.0f", proper_altitude_by_100);
			return;
		}
	}
}

void CKAPChecker::OnFunctionCall(int FunctionId, const char * sItemString, POINT Pt, RECT Area)
{
}

void CKAPChecker::OnFlightPlanFlightPlanDataUpdate(CFlightPlan FlightPlan)
{
	if (!FlightPlan.IsValid())
		return;
}

void CKAPChecker::OnTimer(int Counter)
{
}
