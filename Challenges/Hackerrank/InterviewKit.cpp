#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

namespace hrnk
{
   // Task: https://www.hackerrank.com/challenges/counting-valleys/
   // Time to first submit: 21 min
   // Time to last submit: 24 min
   // Number of submits: 2
   // Errors: 1
   // Debug: no

   int countingValleys(int n, string s) 
   {
      int numValleys = 0;
      int level = 0;
      for (auto c : s)
      {
         if (c == 'U')
         {
            if (++level == 0)
            {
               ++numValleys;
            }
         }
         else
         {
            --level;
         }
      }
      return numValleys;
   }

   // Task: https://www.hackerrank.com/challenges/repeated-string/
   // Time to first submit: 15 min
   // Time to last submit: 15 min
   // Number of submits: 1
   // Errors: 1
   // Debug: no

   long repeatedString(string s, long n) 
   {
      auto numA = count(begin(s), end(s), 'a');
      numA *= (n / s.size());
      int rem = n % s.size();
      if (rem > 0)
      {
         numA += count(&s[0], &s[rem], 'a');
      }
      return numA;
   }

   // Task: https://www.hackerrank.com/challenges/jumping-on-the-clouds/
   // Time to first submit: 27 min
   // Time to last submit: 27 min
   // Number of submits: 1
   // Errors: 5
   // Debug: yes

   int jumpingOnClouds(vector<int> c) 
   {
      // 0010010
      int pos = 0;
      int steps = 0;
      while (pos != c.size() - 1)
      {
         if ((pos < c.size() - 2) && (c[pos + 2] == 0))
         {
            pos += 2;
         }
         else if ((pos < c.size() - 1) && (c[pos + 1] == 0))
         {
            ++pos;
         }
         // else is not necessary as solution always exists per condition
         ++steps;
      }
      return steps;
   }

   vector<string> split_string(string input_string) // function from author, not mine
   {
      string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
         return x == y && x == ' ';
      });

      input_string.erase(new_end, input_string.end());

      while (input_string[input_string.length() - 1] == ' ') {
         input_string.pop_back();
      }

      vector<string> splits;
      char delimiter = ' ';

      size_t i = 0;
      size_t pos = input_string.find(delimiter);

      while (pos != string::npos) {
         splits.push_back(input_string.substr(i, pos - i));

         i = pos + 1;
         pos = input_string.find(delimiter, i);
      }

      splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

      return splits;
   }


} // namespace hrnk


int main_countingValleys()
{
   int n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   string s;
   getline(cin, s);

   int result = hrnk::countingValleys(n, s);

   cout << result << "\n";

   return 0;
}


int main_repeatedString()
{
   string s;
   getline(cin, s);

   long n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   long result = hrnk::repeatedString(s, n);

   cout << result << "\n";

   return 0;
}

int main_jumpingOnClouds()
{
   int n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   string c_temp_temp;
   getline(cin, c_temp_temp);

   vector<string> c_temp = hrnk::split_string(c_temp_temp);

   vector<int> c(n);

   for (int i = 0; i < n; i++) {
      int c_item = stoi(c_temp[i]);

      c[i] = c_item;
   }

   int result = hrnk::jumpingOnClouds(c);

   cout << result << "\n";

   return 0;
}
