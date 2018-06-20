#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct BusesForStopResponse
{
    string stop;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse
{
    string bus;
    vector<pair<string, vector<string>>> stops; // {stop, {interchanges}}
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse
{
    vector<pair<string, vector<string>>> buses; // {bus, {stops}}
};

ostream& operator << (ostream& os, const AllBusesResponse& r);

