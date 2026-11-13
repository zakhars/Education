#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main_04_03()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	string line;
	while (getline(in, line))
	{
		out << line << endl;
	}
	return 0;
}
