#include<vector>
#include <algorithm>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
   size_t sz = v.size();
   vector<int> r(sz);
   for(size_t i = sz - 1; i >=0; i--)
   {
      r[sz - i - 1] = v[i];
   }
   return r;
}
