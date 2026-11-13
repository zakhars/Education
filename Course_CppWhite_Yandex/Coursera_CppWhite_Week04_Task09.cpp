#include <iostream>
using namespace std;

namespace w04_t09
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
    		if (numerator < 0 && denominator < 0 ||
    			numerator > 0 && denominator < 0)
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

}
int main_04_09() {
	using namespace w04_t09;
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
