// https://www.coursera.org/learn/c-plus-plus-white/programming/baBml/raschiot-stoimosti-tovara

#include <iostream>

double get_discounted_price(double initial_price, double percent_discount)
{
   return initial_price - initial_price * percent_discount / 100;
}

int discount()
{
   using namespace std;

   double N, A, B, X, Y;

   cin >> N >> A >> B >> X >> Y;

   if (N > B)
   {
      cout << get_discounted_price(N, Y);
   }
   else if (N > A)
   {
      cout << get_discounted_price(N, X);
   }
   else
   {
      cout << N;
   }

   cout << endl;
   return 0;
}
