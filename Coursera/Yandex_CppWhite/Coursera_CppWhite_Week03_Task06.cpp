#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ReversibleString
{
	string m_s;

public:
	ReversibleString() {}
	ReversibleString(const string& s) : m_s(s) {}
	void Reverse() { reverse(begin(m_s), end(m_s)); }
	const string& ToString() const { return m_s; }

};
