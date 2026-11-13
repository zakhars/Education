#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

namespace w04_t12
{
int NOD(int a, int b)
{
   if (a < b) swap(a, b);

   while (b > 0)
   {
      int r = a % b;
      if (r == 0) return b;
      a = b;
      b = r;
   }

   return 0;
}


class Rational {
public:
    Rational()
	: numerator(0),
	  denominator(1)
	{
    }

    Rational(int numerator_, int denominator_)
    : numerator(numerator_),
	  denominator (denominator_)
    {
    	if (numerator == 0)
    		denominator = 1;
    	else
    	{
    		int nod = NOD(abs(numerator), abs(denominator));
    		numerator /= nod;
    		denominator /= nod;
    		if ((numerator < 0 && denominator < 0) ||
    			(numerator > 0 && denominator < 0))
    		{
    			numerator = -numerator;
    			denominator = -denominator;
    		}
    	}
    }

    int Numerator() const
    {
    	return numerator;
    }

    int Denominator() const
    {
    	return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator== (const Rational& rhs, const Rational& lhs)
{
	return rhs.Numerator() == lhs.Numerator() &&
		   rhs.Denominator() == lhs.Denominator();
}

bool operator< (const Rational& lhs, const Rational& rhs)
{
	int common_denominator = rhs.Denominator() * lhs.Denominator();
	int lNumerator = lhs.Numerator() * (common_denominator / lhs.Denominator());
	int rNumerator = rhs.Numerator() * (common_denominator / rhs.Denominator());

	return lNumerator < rNumerator;
}

Rational operator+ (const Rational& lhs, const Rational& rhs)
{
	int common_denominator = rhs.Denominator() * lhs.Denominator();
	int lNumerator = lhs.Numerator() * (common_denominator / lhs.Denominator());
	int rNumerator = rhs.Numerator() * (common_denominator / rhs.Denominator());

	return {lNumerator + rNumerator, common_denominator};
}

Rational operator- (const Rational& lhs, const Rational& rhs)
{
	int common_denominator = rhs.Denominator() * lhs.Denominator();
	int lNumerator = lhs.Numerator() * (common_denominator / lhs.Denominator());
	int rNumerator = rhs.Numerator() * (common_denominator / rhs.Denominator());

	return {lNumerator - rNumerator, common_denominator};
}

Rational operator* (const Rational& lhs, const Rational& rhs)
{
	int new_numerator = lhs.Numerator() * rhs.Numerator();
	int new_denominator = lhs.Denominator() * rhs.Denominator();

	return {new_numerator, new_denominator};
}

Rational operator/ (const Rational& lhs, const Rational& rhs)
{
	int new_numerator = lhs.Numerator() * rhs.Denominator();
	int new_denominator = lhs.Denominator() * rhs.Numerator();

	return {new_numerator, new_denominator};
}

ostream& operator<< (ostream& os, const Rational& r)
{
	os << r.Numerator() << "/" << r.Denominator();
	return os;
}

istream& operator>> (istream& is, Rational& r)
{
	int n, d;
	is >> n;
	is.ignore(1);
	is >> d;
	r = {n, d};
	return is;
}
}

int main_w04_t12() {
	using namespace w04_t12;
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
