#include <string>

using namespace std;

bool IsPalindrom21(const string& s)
{
	int b = 0;
	int e = s.size() - 1;

	while (b < e)
	{
		if (s[b] != s[e]) return false;
		b++;
		e--;
	}
	return true;
}
