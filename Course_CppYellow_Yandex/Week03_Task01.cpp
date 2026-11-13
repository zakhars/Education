#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Sum(int x, int y)
{
    return x + y;
}
string Reverse(string s)
{
    const size_t sz = s.size();
    for (size_t i = 0; i < sz / 2; ++i)
    {
        swap(s[i], s[sz - i - 1]);
    }
    return s;
}
void Sort(vector<int>& nums)
{
    sort(begin(nums), end(nums));
}

// Teacher's solution:

/*
#include "sum_reverse_sort.h"

#include <algorithm>
using namespace std;

int Sum(int x, int y) {
  return x + y;
}

string Reverse(string s) {
  reverse(s.begin(), s.end());
  return s;
}

void Sort(vector<int>& nums) {
  sort(nums.begin(), nums.end());
}

*/