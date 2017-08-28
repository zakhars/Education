#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

using NameToNames = map<string, vector<string>>;

int main02_13()
{
	NameToNames BusNameToStopNames;
	NameToNames StopNameToBusNames;

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;
		if (command == "NEW_BUS")
		{
			string bus_name;
			int stop_count;
			cin >> bus_name >> stop_count;
			for (int i = 0; i < stop_count; i++)
			{
				string stop_name;
				cin >> stop_name;
				StopNameToBusNames[stop_name].push_back(bus_name);
				BusNameToStopNames[bus_name].push_back(stop_name);
			}
		}
		else if (command == "BUSES_FOR_STOP")
		{
			string stop_name;
			cin >> stop_name;
			auto stop = StopNameToBusNames.find(stop_name);
			if (stop != StopNameToBusNames.end())
			{
				for (auto& bus_name : stop->second)
				{
					cout << bus_name << " ";
				}
			}
			else
			{
				cout << "No stop";
			}
			cout << endl;
		}
		else if (command == "STOPS_FOR_BUS")
		{
			string bus_name;
			cin >> bus_name;
			auto bus = BusNameToStopNames.find(bus_name);
			if (bus != BusNameToStopNames.end())
			{
				auto& stop_names = bus->second;
				for (auto& stop_name : stop_names)
				{
					cout << "Stop " << stop_name << ": ";
					auto stop = StopNameToBusNames.find(stop_name);
					if (stop != StopNameToBusNames.end())
					{
						auto& buses_for_stop = stop->second;
						bool interchange_exists = false;
						for (auto& bus_name_local : buses_for_stop)
						{
							if (bus_name_local != bus_name)
							{
								cout << bus_name_local << " ";
								interchange_exists = true;
							}
						}
						if (!interchange_exists)
						{
							cout << "no interchange";
						}
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No bus" << endl;
			}

		}
		else if (command == "ALL_BUSES")
		{
			if (BusNameToStopNames.empty())
			{
				cout << "No buses" << endl;
			}
			for(auto& bus : BusNameToStopNames)
			{
				cout << "Bus " << bus.first << ": ";
				for (auto& stop_name : bus.second)
				{
					cout << stop_name << " ";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "Invalid command" << endl;
		}
	}

	return 0;
}
