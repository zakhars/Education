#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

namespace leetcode
{
   // Task: https://leetcode.com/problems/two-sum/
   // Time to last submit: 120
   // Number of submits: 10 (did several optimizations)
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
   // Time to first submit: 2:00
   // Time to last submit: 
   // Number of submits: 
   // Errors: 5
   // Debug: no
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
   {
      ListNode* cur = new ListNode(0);
      ListNode* head = cur;
      int mem = 0;
      while (l1 != nullptr && l2 != nullptr)
      {
         int val = l1->val + l2->val + mem;
         if (val > 9)
         {
            mem = 1;
            val %= 10;
         }

         if (cur == nullptr)
         {
            cur = new ListNode(val);
         }

         cur->val = val;
         cur = cur->next;
         l1 = l1->next;
         l2 = l2->next;
      }
      while (l1 != nullptr)
      {
         cur = new ListNode(l1->val + mem);
         cur = cur->next;
         mem = 0;
         l1 = l1->next;
      }
      while (l2 != nullptr)
      {
         cur = new ListNode(l2->val + mem);
         cur = cur->next;
         mem = 0;
         l2 = l2->next;
      }

      return head;
   }


} // namespace leetcode


int main()
{
   using namespace leetcode;
   ListNode* l1 = new ListNode(2); l1->next = new ListNode(4);  l1->next->next = new ListNode(3);
   ListNode* l2 = new ListNode(5); l2->next = new ListNode(6);  l2->next->next = new ListNode(4);
   auto sum = addTwoNumbers(l1, l2);
   while (sum != nullptr)
   {
      cout << sum->val << ' ';
      sum = sum->next;
   }
   return 0;
}
