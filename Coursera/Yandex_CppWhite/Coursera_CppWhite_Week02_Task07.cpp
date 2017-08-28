#include<vector>
#include <algorithm>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
   int sz = v.size();
   vector<int> r(sz);
   for(int i = sz - 1; i >=0; i--)
   {
      r[sz - i - 1] = v[i];
   }
   return r;
}
