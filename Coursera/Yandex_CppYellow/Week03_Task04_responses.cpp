#include <vector>
#include <string>
#include <iostream>

#include "Week03_Task04_responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
    if (r.buses.empty())
    {
        os << "No stop";// << endl;
    }
    else
    {
        for (const string& bus : r.buses)
        {
            os << bus << " ";
        }
        os << endl;
    }
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{
    if (r.stops.empty())
    {
        cout << "No bus";// << endl;
    }
    else
    {
        for (const auto& stop : r.stops)
        {
            cout << "Stop " << stop.first << ": ";
            if (stop.second.size() == 0)
            {
                cout << "no interchange";
            }
            else
            {
                for (const string& bus : stop.second)
                {
                    cout << bus << " ";
                }
            }
            cout << endl;
        }
    }

    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r)
{
    if (r.buses.empty())
    {
        cout << "No buses";// << endl;
    }
    else
    {
        for (const auto& bus : r.buses)
        {
            cout << "Bus " << bus.first << ": ";
            for (const string& stop : bus.second)
            {
                cout << stop << " ";
            }
            cout << endl;
        }
    }
    return os;
}
