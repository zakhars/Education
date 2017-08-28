// https://www.coursera.org/learn/c-plus-plus-white/programming/SG7h0/vtoroie-vkhozhdieniie

#include <iostream>
#include <string>

int find2nd_f()
{
   using namespace std;

   string s;
   cin >> s;
   int result = -2;
   int index = -1;
   for (size_t i = 0; i < s.size(); i++)
   {
      if (s[i] == 'f')
      {
         index = i;
         result++;
      }
      if (result == 0)
      {
         cout << index << endl;
         return 0;
      }
   }
   cout << result << endl;


   return 0;
}
