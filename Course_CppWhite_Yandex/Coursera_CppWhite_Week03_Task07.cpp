#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

using YearToName = map<int, string>;

class Person
{
public:

	Person(const string& first_name, const string& last_name, int year)
	: year_of_birth(year)
	{
		first_names[year] = first_name;
		last_names[year] = last_name;
	}

	// Add fact of changing name to first_name at "year"
	void ChangeFirstName(int year, const string& first_name)
	{
		if (year >= year_of_birth)
		{
			first_names[year] = first_name;
		}
	}

	// Add fact of changing family name to last_name at "year"
	void ChangeLastName(int year, const string& last_name)
	{
		if (year >= year_of_birth)
		{
			last_names[year] = last_name;
		}
	}

	// Get first and last name by the end of year
	string GetFullName(int year) const
	{
		if (year < year_of_birth)
		{
			return "No person";
		}
		string first_name = Person::getNameToYear(first_names, year);
		string last_name  = Person::getNameToYear(last_names, year);
		return Person::getFullName(first_name, last_name);
	}

	string GetFullNameWithHistory(int year) const
	{
		if (year < year_of_birth)
		{
			return "No person";
		}

		string first_name = Person::getNameToYearWithHistory(first_names, year);
		string last_name  = Person::getNameToYearWithHistory(last_names, year);
		return Person::getFullName(first_name, last_name);
	}

private:

	static string getFullName(string first_name, string last_name)
	{
		return first_name + " " + last_name;
	}

	static string getNameToYear(const YearToName& names, int year)
	{
		string name_to_year;
		for (auto& name : names)
		{
			if (name.first <= year)
			{
				name_to_year = name.second;
			}
			else
			{
				break;
			}
		}
		return name_to_year;
	}

	static string getNameToYearWithHistory(const YearToName& names, int year)
	{
		string name_to_year;
		int year_of_name = -1;
		for (auto& name : names)
		{
			if (name.first <= year)
			{
				year_of_name = name.first;
				name_to_year = name.second;
			}
			else
			{
				break;
			}
		}

		if (year_of_name > 0)
		{
			auto it_name = names.find(year_of_name);
			if (it_name == names.begin())
			{
				return name_to_year;
			}

			string cur_name = name_to_year;
			string prev = " (";
			do
			{
            --it_name;
				if (it_name->second != cur_name)
				{
					prev += it_name->second;
					prev += ", ";
               cur_name = it_name->second;
				}
			}
			while (it_name != names.begin());

			if (prev.size() > 2)
			{
				prev.resize(prev.size() - 1);
				prev[prev.size() - 1] = ')';
				name_to_year += prev;
			}
		}

		return name_to_year;
	}

	YearToName first_names;
	YearToName last_names;
	int year_of_birth;

};

