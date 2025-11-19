#define UNKNOWN 0
#define DEPARTURE_GROUND 1
#define DEPARTED 2
#define CRUSING 3
#define APPROACHING 4
#define LANDED 5

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
    bool isVFR;
    bool isSquawkModeC;
    string DepartureAirport;
    string DepartureRunway;
    string DestinationAirport;
    string DestinationRunway;
    string Route;

    int GetTypeOfFlight()
    {
        if (IsAirborne())
        {
            
        }

        return UNKNOWN;
    }

    bool IsAirborne()
    {
        if (GroundSpeed > 60)
            return true;
        return false;
    }

    bool IsInRKRR()
    {
        return (Latitude >= 33.0 && Latitude <= 43.0 && Longitude >= 124.0 && Longitude <= 132.0);
    }

    bool IsAirborneAndApproachingToRKRR()
    {
        if (DestinationAirport.substr(0, 2) == "RK" && IsAirborne())
            return true;
        return false;
    }

    bool HasRoute(const char *airwayOrFix)
    {
        if (Route.find(airwayOrFix) != string::npos)
            return true;
        return false;
    }

    bool IsWestBoundPlan()
    {
        if (HasRoute("Y711"))
            return true;
        if (HasRoute("Y572"))
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

    double CalculateDistanceInNm(CPosition point)
    {
        CPosition mylocation;
        mylocation.m_Latitude = Latitude;
        mylocation.m_Longitude = Longitude;

        return mylocation.DistanceTo(point);
    }
};