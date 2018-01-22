#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom1(const string& s)
{
   size_t first = 0;
   size_t last = s.size() - 1;
   while (last > first)
   {
      if (s[last--] != s[first++]) return false;
   }
   return true;
}

