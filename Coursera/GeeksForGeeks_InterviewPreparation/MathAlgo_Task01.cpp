// https://practice.geeksforgeeks.org/problems/series-ap/0/?track=interview-mathematical

#include <iostream>

using namespace std;

int GetNthAP(int first, int second, int n)
{
   int delta = second - first;
   return first + ((n - 1) * delta);
}

int main_geeksforgeeks01()
{
   int T;
   int first, second;
   int n;
   cin >> T;
   for (size_t i = 0; i < T; ++i)
   {
      cin >> first >> second >> n;
      cout << GetNthAP(first, second, n);
   }
   return 0;
}
