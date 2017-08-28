#include <iostream>
#include <string>
#include <map>
using namespace std;

using YearToName = map<int, string>;

class Person1
{
public:

	// Add fact of changing name to first_name at "year"
	void ChangeFirstName(int year, const string& first_name)
	{
		first_names[year] = first_name;
	}

	// Add fact of changing family name to last_name at "year"
	void ChangeLastName(int year, const string& last_name)
	{
		last_names[year] = last_name;
	}

	// Get first and last name by the end of year
	string GetFullName(int year)
	{
		string first_name = Person1::getNameToYear(first_names, year);
		string last_name  = Person1::getNameToYear(last_names, year);

		if (first_name == "" && last_name == "")
		{
			return "Incognito";
		}
		if (first_name == "")
		{
			return last_name + " with unknown first name";
		}
		if (last_name == "")
		{
			return first_name + " with unknown last name";
		}
		return first_name + " " + last_name;
	}

private:

	static string getNameToYear(const YearToName& names, int year)
	{
		if (names.size() == 0)
		{
			return "";
		}

		auto name_to_year = names.lower_bound(year);
		if (name_to_year == names.end())
		{
			return names.rbegin()->second;
		}
		if (name_to_year->first == year) // exact value
		{
			return name_to_year->second;
		}
		if (name_to_year == names.begin())
		{
			return "";
		}
		return prev(name_to_year)->second;
	}

	YearToName first_names;
	YearToName last_names;

};
