#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>
using namespace std;

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
    {
    	if (denominator_ == 0)
    	{
    		throw invalid_argument("Denominator is 0");
    	}
    	numerator = numerator_;
    	denominator = denominator_;
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
	if (rhs.Numerator() == 0)
	{
		throw domain_error("Domain error");
	}
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

int main_04_15()
{
    try
    {
    	char op;
    	Rational r1, r2;
    	cin >> r1 >> op >> r2;
    	Rational res;
    	switch (op)
    	{
    	case '+': res = r1 + r2; break;
    	case '-': res = r1 - r2; break;
    	case '*': res = r1 * r2; break;
    	case '/': res = r1 / r2; break;
    	default: break;
    	}
    	cout << res;
    }
    catch (invalid_argument&)
    {
    	cout << "Invalid argument" << endl;
    }

    catch (domain_error&)
    {
    	cout << "Division by zero" << endl;
    }

    return 0;
}


