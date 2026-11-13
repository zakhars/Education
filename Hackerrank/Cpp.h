#pragma once

#include <algorithm>
#include <vector>
#include <functional>
#include <limits>
#include <iterator>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>


namespace hrnk
{
   using namespace std;

   namespace cpp
   {
      /// Deque-STL
      /// https://www.hackerrank.com/challenges/deque-stl/problem

      namespace dq
      {
         vector<int> getKMax(deque<int>& arr, int k)
         {
            vector<int> kmax_values;
            const size_t n = arr.size();
            int kmax = *max_element(begin(arr), begin(arr) + k);
            kmax_values.push_back(kmax);
            for (size_t i = k; i < n; i++)
            {
               kmax = std::max(kmax, arr[i]);
               kmax_values.push_back(kmax);
            }
            return kmax_values;
         }

         int run()
         {
            istream& input = istringstream(
               "2 "
               "5 2 "
               "3 4 6 3 4 "
               "7 4 "
               "3 4 5 8 1 4 10"
            );
            //istream& input = cin;

            int t;
            input >> t;
            while (t > 0) 
            {
               int n, k;
               input >> n >> k;
               int i;
               deque<int> arr(n);
               for (i = 0; i < n; i++)
               {
                  input >> arr[i];
               }
               for (auto k : getKMax(arr, k))
               {
                  cout << k << " ";
               }
               cout << endl;
               t--;
            }
            return 0;
         }
      }
   } // cpp
} // hrnk



