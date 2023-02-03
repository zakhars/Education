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
   vector<int> twoSum(vector<int>& nums, int target) 
   {
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

   struct ListNode 
   {
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
		if (l1 == nullptr || l2 == nullptr)
		{
			return nullptr;
		}
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
   // Time to first submit: 60
   // Time to last submit: 150 
   // Number of submits: 5
   // Errors: 6
   // Not passed test cases: aab pwwkew aabaab!bb
   // Debug: yes
   int lengthOfLongestSubstring(string s)
   {
      // abcabcbb -> abc (3)
      // pwwkew -> wke (3)
      // wpwkew -> pwke (4)
      // bbbbb -> b (1)
      // aab -> ab (2)

      unordered_set<char> unique;
      int longest = 0;
      int left = 0;
      int len = 0;

      for (int i = 0; i < s.size(); ++i)
      {
         if (unique.count(s[i]) == 0)
         {
            unique.insert(s[i]);
            if (++len > longest)
            {
               longest = len;
            }
         }
         else
         {
            if (left == i - 1) // 2 equal characters near
            {
               left = i;
               len = 1;
               unique = { s[i] };
            }
            else
            {
               while (s[left] != s[i])
               {
                  unique.erase(s[left]);
                  ++left;
               }
               ++left;
               len = i - left + 1;
            }
         }
      }
      return longest;
   }

   // Task: https://leetcode.com/problems/median-of-two-sorted-arrays/
   // Time to first submit: 15
   // Time to last submit: 20 
   // Number of submits: 2
   // Errors: 1
   // Not passed test cases: 1
   // Debug: yes

   // nums1 = [1, 2]
   // nums2 = [3, 4]
   // Median: (2 + 3) / 2 = 2.5

	// nums1 = [1, 3]
	// nums2 = [2, 4]
	// Median: (2 + 3) / 2 = 2.5

	// nums1 = [1, 3, 5, 7]
	// nums2 = [2, 4, 8]
	// Median: 4

   // nums1 = [1, 3]
   // nums2 = [2]
   // Median: 2.0

   // Complexity should be O(log(m+n))

   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
   {
		vector<int> merged(nums1.size() + nums2.size());
		merge(begin(nums1), end(nums1), begin(nums2), end(nums2), begin(merged));
		const auto sz = merged.size();
		if (sz % 2 == 0)
		{
			return (merged[sz / 2 - 1] + merged[sz / 2]) / 2.0;
		}

      return merged[sz / 2];
   }

	// Task: https://leetcode.com/problems/longest-palindromic-substring/

   class Solution5 {
      bool is_palindrome(const string& s, int b, int e)
      {
         while (b < e)
         {
            if (s[b] != s[e]) return false;
            b++;
            e--;
         }
         return true;

      }
   public:
      string longestPalindrome(string s)
      {
         int pal_len = 0;
         int pal_b = 0;
         int pal_e = 0;
         while (pal_len <= s.length())
         {
            for (int i = 0; i < s.length() - pal_len; ++i)
            {
               if (is_palindrome(s, i, i + pal_len))
               {
                  pal_b = i;
                  pal_e = i + pal_len;
                  break;
               }
            }
            pal_len++;
         }
         return s.substr(pal_b, pal_e - pal_b + 1);
      }
   };

} // namespace leetcode




int main()
{
   using namespace leetcode;
	string s = "ababc";
   cout << Solution5().longestPalindrome(s);

   return 0;
}
