#include <iostream>
#include <cmath>

int quadratic_equation()
{
   using namespace std;

   double a, b, c;
   cin >> a >> b >> c;

   if (a == 0)
   {
      if (b != 0)
      {
         if (c != 0)
         {
            cout << -c / b;
         }
         else
         {
            cout << 0;
         }
      }
      return 0;
   }

   const double D = b*b - 4*a*c;

   if (D > 0)
   {
      cout << (-b + sqrt(D)) / (2*a) << " " << (-b - sqrt(D)) / (2*a);
   }
   else if (D == 0)
   {
      cout << -b / (2*a);
   }

   cout << endl;
   return 0;
}
