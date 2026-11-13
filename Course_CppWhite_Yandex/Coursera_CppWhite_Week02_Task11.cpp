#include <iostream>
#include <string>
#include <map>
using namespace std;

using Dict = map<char, int>;

Dict GetWordDict(const string& s)
{
	Dict dict;
	for (auto c : s)
	{
		dict[c]++;
	}
	return dict;
}

int main02_11()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		cout << (GetWordDict(s1) == GetWordDict(s2) ? "YES" : "NO");
		cout << endl;
	}
	return 0;
}
