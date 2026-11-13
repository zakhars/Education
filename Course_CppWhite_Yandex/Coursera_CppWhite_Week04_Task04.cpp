#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main_04_04()
{
	double a;
	ifstream in("input.txt");
	while (in >> a)
	{
		cout << fixed << setprecision(3) << a << endl;
	}
	return 0;
}
