#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom1(const string& s)
{
   int first = 0;
   int last = s.size() - 1;
   while (last > first)
   {
      if (s[last--] != s[first++]) return false;
   }
   return true;
}

