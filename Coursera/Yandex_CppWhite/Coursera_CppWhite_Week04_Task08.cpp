#include <iostream>
using namespace std;

namespace w04_t08
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

}

int main_04_08() {
	using namespace w04_t08;
    {

    	const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
