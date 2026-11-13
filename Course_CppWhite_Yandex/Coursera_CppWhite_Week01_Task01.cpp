#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include <algorithm>

int compare_strings()
{
   using namespace std;

   set<string> strings;
   copy(istream_iterator<string>(cin), istream_iterator<string>(), inserter(strings, begin(strings)));
   cout << *begin(strings);
   return 0;
}
