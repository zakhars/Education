#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main_02_18()
{
	int n = 0;
	cin >> n;
	int bus_num = 0;
	using Bus = set<string>;
	map<Bus, int> buses;
	for (int i = 0; i < n; i++)
	{
		int num_stops;
		cin >> num_stops;
		Bus bus;
		for (int j = 0; j < num_stops; j++)
		{
			string stop_name;
			cin >> stop_name;
			bus.insert(stop_name);
		}

		if (buses.count(bus) == 0)
		{
			buses[bus] = ++bus_num;
			cout << "New bus " << bus_num << endl;
		}
		else
		{
			cout << "Already exists for " << buses[bus] << endl;
		}
	}

	return 0;
}
