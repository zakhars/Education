#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

vector<size_t> above_average(vector<int64_t> values)
{
   vector<size_t> aa;
   if (values.size() > 0)
   {
      int64_t sum = accumulate(begin(values), end(values), 0LL);
      int64_t avg = sum / static_cast<int64_t>(values.size());

      for (size_t i = 0; i < values.size(); ++i)
      {
         if (values[i] > avg)
         { 
            aa.push_back(i);
         }
      }
   }
   return aa;
}

int main_cpp_y_w1_t1()
{
   size_t n;
   cin >> n;
   vector<int64_t> values(n);
   copy_n(istream_iterator<int64_t>(cin), n, begin(values));

   vector<size_t> aa = above_average(values);
   cout << aa.size() << endl;
   for (auto aai : aa)
   {
      cout << aai << " ";
   }

   return 0;
}


// Teacher's solution
/* 

using namespace std;

int main() 
{
   int n;
   cin >> n;
   vector<int> temperatures(n);
   int64_t sum = 0;
   for (int& temperature : temperatures) 
   {
      cin >> temperature;
      sum += temperature;
   }

   int average = sum / n;

   vector<int> above_average_indices;
   for (int i = 0; i < n; ++i) 
   {
      if (temperatures[i] > average) 
      {
         above_average_indices.push_back(i);
      }
   }

   cout << above_average_indices.size() << endl;
   for (int i : above_average_indices) 
   {
      cout << i << " ";
   }
   cout << endl;

   return 0;
}


*/