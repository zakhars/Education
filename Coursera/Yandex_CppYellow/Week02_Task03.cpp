#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "test_runner.h"

using namespace std;

using YearToName = map<int, string>;

class Person
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
        string first_name = Person::getNameToYear(first_names, year);
        string last_name = Person::getNameToYear(last_names, year);

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

void TestEmpty()
{
    Person p;
    AssertEqual(p.GetFullName(0), "Incognito");
    AssertEqual(p.GetFullName(0), "Incognito");
    AssertEqual(p.GetFullName(1), "Incognito");
}

void TestUnknownFirstName()
{
    Person p;
    AssertEqual(p.GetFullName(2000), "Incognito");
    p.ChangeLastName(2000, "Petrov");
    AssertEqual(p.GetFullName(1999), "Incognito");
    AssertEqual(p.GetFullName(2000), "Petrov with unknown first name");
    AssertEqual(p.GetFullName(2001), "Petrov with unknown first name");
    p.ChangeLastName(2001, "Petrov-Vodkin");
    AssertEqual(p.GetFullName(1999), "Incognito");
    AssertEqual(p.GetFullName(2000), "Petrov with unknown first name");
    AssertEqual(p.GetFullName(2001), "Petrov-Vodkin with unknown first name");
    AssertEqual(p.GetFullName(2002), "Petrov-Vodkin with unknown first name");
}

void TestUnknownLastName()
{
    Person p;
    AssertEqual(p.GetFullName(2000), "Incognito");
    p.ChangeFirstName(2000, "Petr");
    AssertEqual(p.GetFullName(1999), "Incognito");
    AssertEqual(p.GetFullName(2000), "Petr with unknown last name");
    AssertEqual(p.GetFullName(2001), "Petr with unknown last name");
    p.ChangeFirstName(2001, "Petrik");
    AssertEqual(p.GetFullName(1999), "Incognito");
    AssertEqual(p.GetFullName(2000), "Petr with unknown last name");
    AssertEqual(p.GetFullName(2001), "Petrik with unknown last name");
    AssertEqual(p.GetFullName(2002), "Petrik with unknown last name");
}

void TestFullName()
{
    Person p;
    AssertEqual(p.GetFullName(2000), "Incognito");
    p.ChangeFirstName(2000, "Petr");
    p.ChangeLastName(2001, "Petrov");
    AssertEqual(p.GetFullName(1999), "Incognito");
    AssertEqual(p.GetFullName(2000), "Petr with unknown last name");
    AssertEqual(p.GetFullName(2001), "Petr Petrov");
    p.ChangeFirstName(1995, "Petruha");
    AssertEqual(p.GetFullName(1994), "Incognito");
    AssertEqual(p.GetFullName(1995), "Petruha with unknown last name");
    AssertEqual(p.GetFullName(2000), "Petr with unknown last name");
    AssertEqual(p.GetFullName(2001), "Petr Petrov");
    p.ChangeLastName(1985, "Petrov-Viskin");
    AssertEqual(p.GetFullName(1984), "Incognito");
    AssertEqual(p.GetFullName(1985), "Petrov-Viskin with unknown first name");
    AssertEqual(p.GetFullName(1996), "Petruha Petrov-Viskin");
    AssertEqual(p.GetFullName(2000), "Petr Petrov-Viskin");
    AssertEqual(p.GetFullName(2001), "Petr Petrov");
    p.ChangeFirstName(2010, "Uncle Petr");
    AssertEqual(p.GetFullName(2010), "Uncle Petr Petrov");
    p.ChangeLastName(2011, "Petrov-Konyakov");
    AssertEqual(p.GetFullName(2010), "Uncle Petr Petrov");
    AssertEqual(p.GetFullName(2011), "Uncle Petr Petrov-Konyakov");
    AssertEqual(p.GetFullName(2012), "Uncle Petr Petrov-Konyakov");
}


int main_cppy_w01_t03() 
{
    TestRunner runner;
    runner.RunTest(TestEmpty, "TestEmpty");
    runner.RunTest(TestUnknownFirstName, "TestUnknownFirstName");
    runner.RunTest(TestUnknownLastName, "TestUnknownLastName");
    runner.RunTest(TestFullName, "TestFullName");
    return 0;
}

// Teacher's solution:

/*

void TestPredefinedLastNameFirst() {
    Person person;

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeFirstName(1967, "Polina");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
}

void TestPredefined() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");

    person.ChangeFirstName(1969, "Appolinaria");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1969), "Appolinaria Sergeeva");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1967), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1968), "Polina Volkova");
    AssertEqual(person.GetFullName(1969), "Appolinaria Volkova");

}
*/