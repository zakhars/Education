#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int queue_operations()
{
   int n;
   cin >> n;
   vector<int> q;
   for (int i = 0; i < n; i++)
   {
      string command;
      cin >> command;
      int num;

      if (command == "WORRY_COUNT")
      {
         cout << endl << count(begin(q), end(q), 1);
      }
      else
      {
         cin >> num;
         if (command == "COME")
         {
            if (num > 0) q.insert(q.end(), num, 0);
            else q.resize(q.size() + num);
         }
         else if (command == "WORRY")
         {
            q[num] = 1;
         }
         else if (command == "QUIET")
         {
            q[num] = 0;
         }
      }
   }


   return -1;
}
