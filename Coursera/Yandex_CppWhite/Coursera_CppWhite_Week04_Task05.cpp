#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main_04_05()
{
	ifstream in("input.txt");
	int n, m;
	in >> n >> m;
	in.ignore(1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			string s;
			if (j < m - 1)
			{
				getline(in, s, ',');
				int a = stoi(s);
				cout << setw(10) << a  << ' ';
			}
			else
			{
				getline(in, s);
				int a = stoi(s);
				cout << setw(10) << a;
				if (i < n - 1) cout << endl;
			}
		}
	}
	return 0;
}
