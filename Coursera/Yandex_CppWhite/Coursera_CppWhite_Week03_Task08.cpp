#include <iostream>
using namespace std;

class Incognizable
{
	int a;
	int b;
public:
	Incognizable() : a(0), b(0) {};
	Incognizable(int a) : a(a), b(0) {}
	Incognizable(int a, int b) : a(a), b(b) {}
};
