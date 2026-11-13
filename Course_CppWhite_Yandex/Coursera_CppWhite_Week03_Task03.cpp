#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SortedStrings
{
public:
  void AddString(const string& s)
  {
	  strings.push_back(s);
  }
  vector<string> GetSortedStrings()
  {
	  vector<string> ss = strings;
	  sort(begin(ss), end(ss));
	  return ss;
  }
private:
  vector<string> strings;

};
