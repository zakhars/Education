#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(const string& s)
{
   size_t middle = s.size() / 2;
   return true;
}

class A
{
   const string& a;
public: 
   A(const string& s) : a(s) {}

};

int main_palindrome()
{
   string s = "test";
   A a(s);

   cout << "String \"" << s << "\" is " << (IsPalindrome(s) ? "" : "not") << " palindrome" << endl;

   return 0;
}


