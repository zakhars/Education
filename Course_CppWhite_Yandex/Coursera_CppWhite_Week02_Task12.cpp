#include <iostream>
#include <map>
#include <string>
using namespace std;

using CountryInfo = map<string, string>;

void ChangeCapital(CountryInfo& ci, string& country, string& new_capital)
{
	auto c = ci.find(country);
	if(c == ci.end())
	{
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
		ci.insert(make_pair(country, new_capital));
	}
	else
	{
		if (c->second == new_capital)
		{
			cout << "Country " << country << " hasn't changed its capital" << endl;
		}
		else
		{
			cout << "Country " << country << " has changed its capital from " << c->second << " to " << new_capital << endl;
			c->second = new_capital;
		}
	}
}

void Rename(CountryInfo& ci, string& old_country_name, string& new_country_name)
{
	auto co = ci.find(old_country_name);
	auto cn = ci.find(new_country_name);
	if (co == ci.end() || old_country_name == new_country_name || cn != ci.end())
	{
		cout << "Incorrect rename, skip" << endl;
	}
	else
	{
		string capital = co->second;
		cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
		ci.erase(old_country_name);
		ci[new_country_name] = capital;
	}
}

void About(CountryInfo& ci, string& country)
{
	auto c = ci.find(country);
	if (c != ci.end())
	{
		cout << "Country " << country << " has capital " << c->second << endl;
	}
	else
	{
		cout << "Country " << country << " doesn't exist" << endl;
	}
}

void Dump(CountryInfo& ci)
{
	if (ci.size() == 0)
	{
		cout << "There are no countries in the world" << endl;
	}
	else
	{
		for(auto& c : ci)
		{
			cout << c.first << "/" << c.second << " ";
		}
		cout << endl;
	}
}

int main02_12()
{
	int q;
	cin >> q;
	CountryInfo ci;
	for(int i = 0; i < q; i++)
	{
		string command;
		cin >> command;
		if(command == "CHANGE_CAPITAL")
		{
			string country, new_capital;
			cin >> country >> new_capital;
			ChangeCapital(ci, country, new_capital);
		}
		else if (command == "RENAME")
		{
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			Rename(ci, old_country_name, new_country_name);
		}
		else if (command == "ABOUT")
		{
			string country;
			cin >> country;
			About(ci, country);
		}
		else if (command == "DUMP")
		{
			Dump(ci);
		}
		else
		{
			cout << "Invalid command" << endl;
		}
	}
	return 0;
}
