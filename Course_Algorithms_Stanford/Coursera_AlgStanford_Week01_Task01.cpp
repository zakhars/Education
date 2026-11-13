#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int mul_with_carry(int m1, int m2, int& carry)
{
   int res = m1 * m2 + carry;
   if (res > 9)
   {
      carry = res / 10;
      res = res % 10;
   }
   else
   {
      carry = 0;
   }
   return res;
}

string Multiply(string m1, string  m2)
{
   if (m1.length() < m2.length())
   {
      swap (m1, m2);
   }

   vector<string> terms(m2.length());
   size_t term_size = m1.length() + m2.length();
   for(auto& t : terms)
   {
      t.resize(term_size, '0');
   }

   int shift = 0;
   int ti = 0;
   for (size_t m2i = m2.size() - 1; m2i >= 0; m2i--)
   {
      int carry = 0;
      size_t termi = term_size - shift - 1;
      for (size_t m1i = m1.size() - 1; m1i >= 0; m1i--)
      {
         terms[ti][termi--] = mul_with_carry(m2[m2i] - '0', m1[m1i] - '0', carry) + '0';
      }
      if (carry)
      {
         terms[ti][termi] = carry + '0';
      }
      shift++;
      ti++;
   }

   int carry = 0;
   string result;
   result.resize(term_size);
   size_t i = term_size - 1;
   for (; i >=0; i--)
   {
      int sum = 0;
      for(auto& t : terms)
      {
         sum += (t[i] - '0');
      }
      sum += carry;
      if (sum > 9)
      {
         carry = sum / 10;
         sum = sum % 10;
      }
      else
      {
         carry = 0;
      }
      result[i] = sum + '0';
   }
   if (carry)
   {
      result[i] = carry + '0';
   }

   cout << m1 << endl << m2 << endl << "-----------------------" << endl;

   for (auto& t : terms)
   {
      cout << t << endl;
   }

   cout << "-----------------------" << endl;

   return result;
}


int main_w01_t01()
{
   cout << Multiply("3141592653589793238462643383279502884197169399375105820974944592", "2718281828459045235360287471352662497757247093699959574966967627") << endl;
   return 0;
}