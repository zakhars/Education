#include <vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v)
{
   size_t b = 0;
   size_t e = v.size() - 1;
   while (b < e)
   {
      swap(v[b++], v[e--]);
   }
}

