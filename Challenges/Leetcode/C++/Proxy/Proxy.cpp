#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
	if (s == "") return "";
	if (numRows == 1) return s;

	char** m = new char* [numRows];
	int numCols = s.size();
	for (int i = 0; i < numRows; i++)
	{
		m[i] = new char[numCols]();
	}

	m[0][0] = s[0];
	int col = 0;
	int i = 1;
	while(i < s.size())
	{
		for (int row = 1; row < numRows && i < s.size(); row++)
			m[row][col] = s[i++];
		for (int row = numRows - 2; row >= 0 && i < s.size(); row--)
			m[row][++col] = s[i++];
	}

	string res;
	res.reserve(s.size());
	for (int row = 0; row < numRows; row++)
		for (int col = 0; col < numCols; col++)
			if (m[row][col] != 0)
				res.push_back(m[row][col]);

	return res;
}


int main()
{
	cout << convert("PAYPALISHIRING", 3) << endl;
}
