#include <iostream>
#include <vector>
#include <algorithm>

int main1()
{
   using namespace std;

   int n;
   cin >> n;

   vector<int> rep;
   while (n > 0)
   {
      char bit = (n <<= 1);
      rep.push_back(bit);
   }

   for(auto b : rep) cout << b;

   return 0;
}
