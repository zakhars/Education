#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main_03_01()
{
	int n;
	cin >> n;
	vector<int> v(n);
	copy_n(istream_iterator<int>(cin), n, begin(v));
	sort(begin(v), end(v), [](int lhs, int rhs) { return abs(lhs) < abs(rhs); });
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));

	return 0;
}
