#include <string>

using namespace std;

bool IsPalindrom21(const string& s)
{
	size_t b = 0;
	size_t e = s.size() - 1;

	while (b < e)
	{
		if (s[b] != s[e]) return false;
		b++;
		e--;
	}
	return true;
}
