#include <map>
#include <vector>
#include <string>
#include <iostream>

#include  "Week03_Task04_bus_manager.h"
#include  "Week03_Task04_responses.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops)
{
    buses_to_stops[bus] = stops;
    for (const string& stop : stops)
    {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const
{
    BusesForStopResponse r = { stop,{} };
    if (stops_to_buses.count(stop) > 0)
    {
        r.buses = stops_to_buses.at(stop);
    }
    return r;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const
{
    StopsForBusResponse r = { bus,{} };
    if (buses_to_stops.count(bus) > 0)
    {
        for (const string& stop : buses_to_stops.at(bus))
        {
            vector<string> interchanges;
            for (const string& other_bus : stops_to_buses.at(stop))
            {
                if (bus != other_bus)
                {
                    interchanges.push_back(other_bus);
                }
            }
            r.stops.push_back({ stop, interchanges });
        }
    }
    return r;
}

AllBusesResponse BusManager::GetAllBuses() const
{
    AllBusesResponse r;

    for (const auto& bus_item : buses_to_stops)
    {
        r.buses.push_back({ bus_item.first, bus_item.second });
    }

    return r;
}

