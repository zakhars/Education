#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

namespace leetcode
{
   // Task: https://leetcode.com/problems/two-sum/
   // Time to first submit: 13
   // Time to last submit: 13
   // Number of submits: 1
   // Errors: 2
   // Debug: no
   vector<int> twoSum(vector<int>&& nums, int target) {
      vector<int> indices;
      for (int i = 0; i < nums.size(); ++i)
      {
         for (int j = i + 1; j < nums.size(); ++j)
         {
            if (nums[i] + nums[j] == target)
            {
               indices.push_back(i);
               indices.push_back(j);
               return indices;
            }
         }
      }
      return indices;
   }


} // namespace leetcode


int main()
{
   auto indices = leetcode::twoSum({2, 4, 3}, 5);
   for (auto i : indices) cout << i << ' ';
   return 0;
}
