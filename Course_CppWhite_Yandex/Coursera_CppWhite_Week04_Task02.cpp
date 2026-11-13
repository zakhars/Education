#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main_04_02()
{
	ifstream in("input.txt");
	string line;
	while (getline(in, line))
	{
		cout << line << endl;
	}
	return 0;
}
