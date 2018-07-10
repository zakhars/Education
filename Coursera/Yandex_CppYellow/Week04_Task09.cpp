#include <iostream>
#include <string>
#include <map>
using namespace std;

namespace
{
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
}

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

// Teacher's solution:

/*
#include <map>
#include <string>

// Возвращает пустую строку, если имя неизвестно
string FindNameByYear(const map<int, string>& names, int year) {
  auto iter_after = names.upper_bound(year);
  string name;
  if (iter_after != names.begin()) {
    name = (--iter_after)->second;
  }
  return name;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    } else {
      return first_name + " " + last_name;
    }
  }
private:
  map<int, string> first_names;
  map<int, string> last_names;
};
*/