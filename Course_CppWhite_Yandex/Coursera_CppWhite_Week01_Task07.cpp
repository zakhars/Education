#include <iostream>

int nod()
{
   using namespace std;

   int a, b;
   cin >> a >> b;

   if (a < b) swap(a, b);

   while (b > 0)
   {
      int r = a % b;
      if (r == 0) cout << b << endl;
      a = b;
      b = r;
   }

   return 0;
}
