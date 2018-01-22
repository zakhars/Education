#include <iostream>
#include <vector>
using namespace std;

int average(const vector<int>& v)
{
   int avg = 0;
   for(auto vi : v)
   {
      avg += vi;
   }
   return avg / static_cast<int>(v.size());
}

int print()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for (auto& vi : v)
   {
      cin >> vi;
   }

   int avg = average(v);
   int count = 0;
   for (auto vi : v)
   {
      if (vi > avg)
      {
         count++;
      }
   }

   cout << count << endl;

   for (size_t i = 0; i < v.size(); i++)
   {
      if (v[i] > avg)
      {
         cout << i << " ";
      }
   }

   return 0;
}
