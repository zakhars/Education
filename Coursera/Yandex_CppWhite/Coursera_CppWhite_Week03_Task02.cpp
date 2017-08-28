#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main_03_02()
{
	int n;
	cin >> n;
	vector<string> v(n);
	copy_n(istream_iterator<string>(cin), n, begin(v));
	sort(begin(v), end(v),
		[](const string& l, const string& r)
		{
			return lexicographical_compare(begin(l), end(l), begin(r), end(r),
				[](char lc, char rc)
				{
					return tolower(lc) < tolower(rc);
				});
		});
	copy_n(begin(v), n, ostream_iterator<string>(cout, " "));
	return 0;
}
