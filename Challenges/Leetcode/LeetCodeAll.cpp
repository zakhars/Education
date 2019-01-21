#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

namespace leetcode
{
   // Task: https://leetcode.com/problems/two-sum/
   // Time to first submit: 13
   // Time to last submit: 120
   // Number of submits: 10
   // Errors: 5
   // Debug: yes
   vector<int> twoSum(vector<int>& nums, int target) {
      unordered_set<int> hashed(begin(nums), end(nums));
      for (int i = 0; i < nums.size(); ++i)
      {
         auto second = target - nums[i];
         if (hashed.count(second) != 0)
         {
            auto found_it = find(begin(nums) + i + 1, end(nums), second);
            if (found_it != end(nums))
            {
               int j = static_cast<int>(distance(begin(nums), found_it));
               return { i,j };
            }
         }
      }
      return {};
   }

   struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(nullptr) {}
   };

   // Task: https://leetcode.com/problems/add-two-numbers/
   // Time to first submit: 0:00
   // Time to last submit: 
   // Number of submits: 
   // Errors: 
   // Debug: no
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
   {
      return {};
   }


} // namespace leetcode


int main()
{
   using namespace leetcode;
   ListNode* l1 = new ListNode(2, new ListNode(4, (new ListNode(3)));
   
    
   ListNode* l2;
   auto sum = addTwoNumbers(l1, l2);
   while (sum != nullptr)
   {
      cout << sum->val << ' ';
      sum = sum->next;
   }
   return 0;
}
