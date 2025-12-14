// global fix maps
unordered_map<std::string, CPosition> fir_boundary_fix_map;
unordered_map<std::string, CPosition> fix_map;
unordered_map<std::string, CPosition> airport_map;
unordered_map<std::string, CPosition> runway_map;

#define UNKNOWN 0
#define CLEARANCE 1
#define PUSHBACK 2
#define TAXI_TO_RUNWAY 3
#define READY_FOR_DEP 4
#define DEPARTURE_ROLLING 5
#define CLIMBING 6
#define CRUISING 7
#define ARRIVAL 8
#define APPROACHING 9
#define LANDING_ROLLING 10
#define TAXI_TO_GATE 11
#define PARKED_AT_GATE 12

class CKAPInfo
{
public:
    double Latitude;
    double Longitude;
    int Altitude;
    int TempAltitude;
    int FinalAltitude;
    double Heading;
    double GroundSpeed;
    int VerticalSpeed;
    bool isVFR;
    string PlanSquawk;
    string CurrentSquawk;
    bool isSquawkModeC;
    string DepartureAirport;
    string DepartureRunway;
    string Sid;
    string DestinationAirport;
    string DestinationRunway;
    string Star;
    string Route;
    string ScratchPadString;

    CPosition MyPosition()
    {
        CPosition pos;
        pos.m_Latitude = Latitude;
        pos.m_Longitude = Longitude;
        return pos;
    }

    int GetTypeOfFlight()
    {
        bool isCloserToDeparture = isCloserToDepartureThanArrival();

        if (isCloserToDeparture)
        {
            if (PlanSquawk == "" || PlanSquawk == "0000")
            {
                return CLEARANCE;
            }

            if (IsAirborne())
            {
                if (Altitude < 20000)
                {
                    return CLIMBING;
                }
                else
                {
                    return CRUISING;
                }
            }

            // check 0.15 nm in departure runway
            string AirportAndDepartureRunway = DepartureAirport + "-" + DepartureRunway;
            if (runway_map.contains(AirportAndDepartureRunway))
            {
                CPosition runwayPos = runway_map[AirportAndDepartureRunway];
                CPosition mylocation = MyPosition();

                double distanceToRunway = mylocation.DistanceTo(runwayPos);
                if (distanceToRunway < 0.2)
                {
                    return READY_FOR_DEP;
                }
            }

            if (IsMoving())
            {
                if (IsOnDepartureRunway())
                {
                    return DEPARTURE_ROLLING;
                }

                return TAXI_TO_RUNWAY;
            }

            return PUSHBACK;
        }
        else
        {
            if (!IsAirborne())
            {
                if (IsOnDestinationRunway())
                {
                    return LANDING_ROLLING;
                }

                if (IsMoving())
                {
                    return TAXI_TO_GATE;
                }

                return PARKED_AT_GATE;
            }

            if (IsClearedApproach() || IsClearedVisualApproach())
            {
                return APPROACHING;
            }

            if (Altitude < 20000)
            {
                return ARRIVAL;
            }

            return CRUISING;
        }

        return UNKNOWN;
    }

    string GetTypeOfFlightString()
    {
        int type = GetTypeOfFlight();
        switch (type)
        {
        case CLEARANCE:
            return "CLEARANCE";
        case PUSHBACK:
            return "PUSHBACK";
        case TAXI_TO_RUNWAY:
            return "TAXI_TO_RUNWAY";
        case READY_FOR_DEP:
            return "READY_FOR_DEP";
        case DEPARTURE_ROLLING:
            return "DEPARTURE_ROLLING";
        case CLIMBING:
            return "CLIMBING";
        case CRUISING:
            return "CRUISING";
        case ARRIVAL:
            return "ARRIVAL";
        case APPROACHING:
            return "APPROACHING";
        case LANDING_ROLLING:
            return "LANDING_ROLLING";
        case TAXI_TO_GATE:
            return "TAXI_TO_GATE";
        case PARKED_AT_GATE:
            return "PARKED_AT_GATE";
        default:
            return "UNKNOWN";
        }
    }

    bool IsAirborne()
    {
        if (GroundSpeed > 60 || VerticalSpeed > 50)
            return true;
        return false;
    }

    bool IsMoving()
    {
        if (GroundSpeed > 3)
            return true;
        return false;
    }

    bool IsDestinationRKRR()
    {
        if (DestinationAirport.find("RK") == 0)
            return true;
        return false;
    }

    bool IsOnDepartureRunway()
    {
        return (DistanceMyLocationFromRunway(DepartureAirport, DepartureRunway) < 0.001);
    }

    bool IsOnDestinationRunway()
    {
        return (DistanceMyLocationFromRunway(DestinationAirport, DestinationRunway) < 0.001);
    }

    double DistanceMyLocationFromRunway(const string &airport, const string &runway)
    {
        string runwayName = airport + "-" + runway;

        if (!runway_map.contains(runwayName))
        {
            return 100000.0;
        }

        CPosition runwayPos = runway_map[runwayName];
        CPosition runwayOppositePos = runway_map[runwayName + "-OPPOSITE"];

        double px = Longitude;
        double py = Latitude;

        double x1 = runwayPos.m_Longitude;
        double y1 = runwayPos.m_Latitude;
        double x2 = runwayOppositePos.m_Longitude;
        double y2 = runwayOppositePos.m_Latitude;

        double dx = x2 - x1;
        double dy = y2 - y1;
        double segLen2 = dx * dx + dy * dy;

        if (segLen2 == 0.0)
        {
            return hypot(px - x1, py - y1);
        }

        double t = ((px - x1) * dx + (py - y1) * dy) / segLen2;

        if (t < 0.0)
        {
            return hypot(px - x1, py - y1);
        }
        else if (t > 1.0)
        {
            return hypot(px - x2, py - y2);
        }

        double projX = x1 + t * dx;
        double projY = y1 + t * dy;

        return hypot(px - projX, py - projY);
    }

    static bool PointInPolygon(const std::vector<std::pair<double, double>> &poly, double x, double y)
    {
        bool inside = false;
        int n = (int)poly.size();
        if (n < 3)
            return false;

        for (int i = 0, j = n - 1; i < n; j = i++)
        {
            double xi = poly[i].first, yi = poly[i].second;
            double xj = poly[j].first, yj = poly[j].second;

            bool intersect = ((yi > y) != (yj > y)) &&
                             (x < (xj - xi) * (y - yi) / (yj - yi + 0.0) + xi);
            if (intersect)
                inside = !inside;
        }
        return inside;
    }

    bool isCloserToDepartureThanArrival()
    {
        double distanceToDeparture = GetDistanceFromDepartureInNm();
        double distanceToArrival = GetDistanceFromDestinationInNm();

        return distanceToDeparture < distanceToArrival;
    }

    bool IsInRKRR()
    {
        static const vector<pair<double, double>> rkrrBoundary = {
            {124.0, 38.0},
            {124.85, 38.0},
            {124.90277722222223, 37.9527775},
            {124.8916663888889, 37.875},
            {124.955555, 37.75833277777778},
            {125.15277722222223, 37.61666666666667},
            {125.32606333333332, 37.616661666666666},
            {125.38245583333332, 37.635398055555555},
            {125.52422416666667, 37.68642833333333},
            {125.75442861111111, 37.718853611111115},
            {126.01838777777778, 37.6641025},
            {126.17973333333333, 37.72629555555556},
            {126.21013194444444, 37.8151175},
            {126.35555527777777, 37.84722166666667},
            {126.43888833333334, 37.84722166666667},
            {126.59166666666667, 37.77222222222222},
            {126.68333333333334, 37.80833305555555},
            {126.68333333333334, 37.9527775},
            {126.78611111111111, 37.96666666666667},
            {126.86944416666665, 38.041666388888885},
            {126.87777777777777, 38.1},
            {126.96111083333334, 38.144444444444446},
            {126.96944444444445, 38.21666666666667},
            {127.1416663888889, 38.31944388888889},
            {127.23333333333333, 38.34166666666667},
            {127.29999972222222, 38.32222222222222},
            {127.3916663888889, 38.333333333333336},
            {127.50833333333334, 38.30277722222222},
            {127.56944416666666, 38.333333333333336},
            {127.66444444444446, 38.33888888888889},
            {127.78611111111111, 38.34722166666667},
            {127.82222222222222, 38.31944388888889},
            {127.8916663888889, 38.333333333333336},
            {128.04722166666667, 38.31666666666667},
            {128.1361111111111, 38.33888833333334},
            {128.25555555555556, 38.41111111111111},
            {128.3, 38.47222166666667},
            {128.3138888888889, 38.59722166666667},
            {128.36666666666667, 38.63333333333333},
            {133.647211, 38.6361},
            {132.997222, 38.002778},
            {132.997222, 37.502778},
            {130.33006, 35.52823},
            {129.166667, 34.666667},
            {127.5, 32.5},
            {126.833333, 32.5},
            {125.416667, 30.0},
            {124.0, 30.0},
            {124.0, 36.36},
            {124.0, 38.0}};
        return PointInPolygon(rkrrBoundary, Longitude, Latitude);
    }

    bool IsSquawkCodeMatched()
    {
        if (PlanSquawk == CurrentSquawk)
            return true;
        return false;
    }

    bool HasRoute(const char *airwayOrFix)
    {
        if (Route.find(airwayOrFix) != string::npos)
            return true;
        return false;
    }

    bool IsWestBoundFlying()
    {
        if (Heading > 190.0 && Heading < 350.0)
            return true;

        return false;
    }

    bool IsEastBoundFlying()
    {
        if (Heading > 10.0 && Heading < 170.0)
            return true;

        return false;
    }

    bool IsNorthBoundFlying()
    {
        if (Heading > 280.0 || Heading < 80.0)
            return true;

        return false;
    }

    bool IsSouthBoundFlying()
    {
        if (Heading > 100.0 && Heading < 260.0)
            return true;

        return false;
    }

    bool IsWestBoundPlan()
    {
        if (HasRoute("Y711"))
            return true;
        if (HasRoute("Y572"))
            return true;
        if (HasRoute("Z53"))
            return true;
        if (HasRoute("MUGUS"))
            return true;
        if (HasRoute("KALEK Z84"))
            return true;
        if (HasRoute("TOSAN Y572"))
            return true;
        if (HasRoute("TOSAN A586"))
            return true;
        if (HasRoute("ANSIM G597 AGAVO"))
            return true;
        if (HasRoute("NOPIK G597 AGAVO"))
            return true;
        if (HasRoute("BINIL G597 AGAVO"))
            return true;
        if (HasRoute("LIMDI Y677 TOLIS"))
            return true;
        if (HasRoute("SADLI A593 LAMEN"))
            return true;
        if (HasRoute("PONIK A593 LAMEN"))
            return true;
        if (HasRoute("TOPAX A586 MAKET"))
            return true;

        return false;
    }
    bool IsEastBoundPlan()
    {
        if (HasRoute("Y722"))
            return true;
        if (HasRoute("Y644"))
            return true;
        if (HasRoute("Y781"))
            return true;
        if (HasRoute("Y571"))
            return true;
        if (HasRoute("Y590"))
            return true;
        if (HasRoute("Y209"))
            return true;
        if (HasRoute("Z84 KALEK"))
            return true;
        if (HasRoute("Y697 LANAT"))
            return true;
        if (HasRoute("G597 LANAT"))
            return true;
        if (HasRoute("Y579 TENAS"))
            return true;
        if (HasRoute("L512 ANDOL"))
            return true;
        if (HasRoute("Y233 KANSU"))
            return true;
        if (HasRoute("G597 BIKSI"))
            return true;
        if (HasRoute("Y697 BIKSI"))
            return true;
        if (HasRoute("G597 KAE"))
            return true;
        if (HasRoute("Y697 KAE"))
            return true;
        if (HasRoute("OSPOT A582"))
            return true;
        if (HasRoute("OSPOT Y782"))
            return true;
        if (HasRoute("TAMNA A595"))
            return true;
        if (HasRoute("TAMNA Y677"))
            return true;
        if (HasRoute("PSN G339 INVOK"))
            return true;
        if (HasRoute("PSN Z91 INVOK"))
            return true;
        if (HasRoute("PSN A582 APELA"))
            return true;
        if (HasRoute("PSN Y782 APELA"))
            return true;
        if (HasRoute("MAKET A586 TOPAX"))
            return true;

        return false;
    }

    bool IsClearedApproach()
    {
        return (TempAltitude == 1);
    }

    bool IsClearedVisualApproach()
    {
        return (TempAltitude == 2);
    }

    int GetTempOrFinalAltitude()
    {
        if (TempAltitude <= 0)
            return FinalAltitude;
        if (TempAltitude == 1 || TempAltitude == 2)
            return 0;
        return TempAltitude;
    }

    bool IsFinalOddLevel()
    {
        if (FinalAltitude == 5000 ||
            FinalAltitude == 7000 ||
            FinalAltitude == 9000 ||
            FinalAltitude == 11000 ||
            FinalAltitude == 13000 ||
            FinalAltitude == 15000 ||
            FinalAltitude == 17000 ||
            FinalAltitude == 19000 ||
            FinalAltitude == 21000 ||
            FinalAltitude == 23000 ||
            FinalAltitude == 25000 ||
            FinalAltitude == 27000 ||
            FinalAltitude == 29000 ||
            FinalAltitude == 31000 ||
            FinalAltitude == 33000 ||
            FinalAltitude == 35000 ||
            FinalAltitude == 37000 ||
            FinalAltitude == 39000)
            return true;

        return false;
    }
    bool IsFinalEvenLevel()
    {
        if (FinalAltitude == 4000 ||
            FinalAltitude == 6000 ||
            FinalAltitude == 8000 ||
            FinalAltitude == 10000 ||
            FinalAltitude == 12000 ||
            FinalAltitude == 14000 ||
            FinalAltitude == 16000 ||
            FinalAltitude == 18000 ||
            FinalAltitude == 20000 ||
            FinalAltitude == 22000 ||
            FinalAltitude == 24000 ||
            FinalAltitude == 26000 ||
            FinalAltitude == 28000 ||
            FinalAltitude == 30000 ||
            FinalAltitude == 32000 ||
            FinalAltitude == 34000 ||
            FinalAltitude == 36000 ||
            FinalAltitude == 38000)
            return true;
        return false;
    }

    double GetDistanceFromDepartureInNm()
    {
        if (!airport_map.contains(DepartureAirport))
            return 0.0;

        CPosition departurePos = airport_map[DepartureAirport];
        CPosition mylocation = MyPosition();

        return mylocation.DistanceTo(departurePos);
    }

    double GetDistanceFromDestinationInNm()
    {
        if (!airport_map.contains(DestinationAirport))
            return 0.0;

        CPosition destinationPos = airport_map[DestinationAirport];
        CPosition mylocation = MyPosition();

        return mylocation.DistanceTo(destinationPos);
    }

    bool NeedExpeditedDescent()
    {
        if (Altitude > GetProperAltitudeForDestination())
        {
            return true;
        }

        return false;
    }
    bool NeedDescent()
    {
        if (Altitude * 1.5 > GetProperAltitudeForDestination())
        {
            return true;
        }

        return false;
    }

    double GetProperAltitudeForDestination()
    {
        // show proper altitude (by 1nm = 300ft rule)
        double distance_to_destination = GetDistanceFromDestinationInNm();

        if (distance_to_destination <= 0.0)
            return 0.0;

        return distance_to_destination * 3.2 * 100;
    }

    double CalculateDistanceInNm(CPosition point)
    {
        CPosition mylocation = MyPosition();

        return mylocation.DistanceTo(point);
    }
};