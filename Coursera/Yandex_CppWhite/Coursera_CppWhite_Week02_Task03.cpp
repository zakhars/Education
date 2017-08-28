#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(const string& s)
{
   int first = 0;
   int last = s.size() - 1;
   while (last > first)
   {
      if (s[last--] != s[first++]) return false;
   }
   return true;
}

vector<string> PalindromFilter(const vector<string>& words, size_t minLength)
{
   vector<string> filtered;
   for(const auto& word : words)
   {
      if (word.size() >= minLength && IsPalindrom(word))
      {
         filtered.push_back(word);
      }
   }
   return filtered;
}

