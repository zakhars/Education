#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

namespace leetcode
{
   // Task: https://leetcode.com/problems/two-sum/
   // Time to first submit: 20
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
   // Time to first submit: 120
   // Time to last submit: 140 
   // Number of submits: 5
   // Errors: 9
   // Debug: yes
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
   {
      ListNode* tail = nullptr;
      ListNode* head = nullptr;
      int mem = 0;
      while (l1 != nullptr && l2 != nullptr)
      {
         int val = l1->val + l2->val + mem;
         if (val > 9)
         {
            mem = 1;
            val %= 10;
         }
         else
         {
            mem = 0;
         }

         if (head == nullptr)
         {
            head = new ListNode(val);
            tail = head;
         }
         else
         {
            tail->next = new ListNode(val);
            tail = tail->next;
         }

         l1 = l1->next;
         l2 = l2->next;
      }
      while (l1 != nullptr)
      {
         int val = l1->val + mem;
         if (val > 9)
         {
            mem = 1;
            val %= 10;
         }
         else
         {
            mem = 0;
         }
         tail->next = new ListNode(val);
         tail = tail->next;
         l1 = l1->next;
      }
      while (l2 != nullptr)
      {
         int val = l2->val + mem;
         if (val > 9)
         {
            mem = 1;
            val %= 10;
         }
         else
         {
            mem = 0;
         }
         tail->next = new ListNode(val);
         tail = tail->next;
         l2 = l2->next;
      }

      if (mem != 0)
      {
         tail->next = new ListNode(mem);
         tail = tail->next;
      }

      return head;
   }

   // Task: https://leetcode.com/problems/longest-substring-without-repeating-characters/
   // Time to first submit: 10:30
   // Time to last submit:  
   // Number of submits: 0
   // Errors: 1
   // Not passed test cases:
   // Debug: no
   int lengthOfLongestSubstring(string s)
   {
      // abcabcbb -> abc (3)
      // pwwkew -> wke (3)
      // wpwkew -> pwke (4)
      // bbbbb -> b (1)

      unordered_set<char> seq;
      int longest = 0;
      int pos = 0;
      int len = 0;

      for (auto c : s)
      {
         if (seq.count(c) == 0)
         {
            seq.insert(c);
            ++len;
            if (len > longest)
            {
               longest = len;
            }
         }
         else
         {
            while (s[pos] != c)
            {
               ++pos;
               --len;
               seq.erase(c);
            }
            --len;
            ++pos;
         }
      }
      return longest;
   }


} // namespace leetcode


int main()
{
   using namespace leetcode;

   cout << lengthOfLongestSubstring("abcabcb") << endl;
   cout << lengthOfLongestSubstring("pwwkew") << endl;
   cout << lengthOfLongestSubstring("wpwkew") << endl;
   cout << lengthOfLongestSubstring("bbbbb") << endl;
   return 0;
}
