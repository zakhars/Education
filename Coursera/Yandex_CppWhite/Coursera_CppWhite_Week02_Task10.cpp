#include <iostream>
#include <vector>
#include <string>
using namespace std;

void NextMonth(vector<vector<string>>& month, int new_days)
{
   int old_days = month.size();

   vector<string> records_left;
   if (new_days < old_days)
   {
      for(int i = new_days; i < old_days; i++)
      {
         auto& d = month[i];
         records_left.insert(end(records_left), begin(d), end(d));
      }
   }

   month.resize(new_days);
   if (records_left.size() > 0)
   {
      auto& last_day = month[new_days - 1];
      last_day.insert(end(last_day), begin(records_left), end(records_left));
   }
}

int main02_10()
{
   vector<int> days_per_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int current_month = 0;
   int num_days = days_per_month[current_month];
   vector<vector<string>> month(num_days);

   int num_commands;
   cin >> num_commands;
   while (num_commands)
   {
      string command;
      cin >> command;

      if (command == "ADD")
      {
         int day;
         string business;
         cin >> day >> business;
         day--;
         month[day].push_back(business);
      }
      else if (command == "DUMP")
      {
         int day;
         cin >> day;
         day--;
         cout << month[day].size();
         for (const auto& b : month[day]) cout << " " << b;
         cout << endl;
      }
      else if (command == "NEXT")
      {
         current_month = (current_month + 1) % 12;
         num_days = days_per_month[current_month];
         NextMonth(month, num_days);
      }
      else
      {
         cout << "Wrong command" << endl;
      }
      num_commands--;
   }


   return 0;
}
