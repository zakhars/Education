#include <vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v)
{
   int b = 0;
   int e = v.size() - 1;
   while (b < e)
   {
      swap(v[b++], v[e--]);
   }
}

