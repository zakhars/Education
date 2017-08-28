#include <iostream>
#include <sstream>
using namespace std;

namespace w04_t11
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
int main_04_11() {
	using namespace w04_t11;
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
