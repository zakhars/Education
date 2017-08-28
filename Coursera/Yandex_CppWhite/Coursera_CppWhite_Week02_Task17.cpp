#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main_02_17()
{
	int n;
	cin >> n;

	map<string, set<string>> synonims;

	for (int i = 0; i < n; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "ADD")
		{
			string w1, w2;
			cin >> w1 >> w2;
			synonims[w1].insert(w2);
			synonims[w2].insert(w1);
		}
		else if (cmd == "COUNT")
		{
			string w;
			cin >> w;
			if (synonims.count(w) == 0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << synonims[w].size() << endl;
			}
		}
		else if (cmd == "CHECK")
		{
			string w1, w2;
			cin >> w1 >> w2;
			if (synonims.count(w1) > 0 && synonims[w1].count(w2) > 0 ||
				synonims.count(w2) > 0 && synonims[w2].count(w1) > 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			cout << "Invalid query" << endl;
		}
	}
	return 0;
}
