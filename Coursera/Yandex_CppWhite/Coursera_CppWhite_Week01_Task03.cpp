#include <iostream>

int divide()
{
   using namespace std;
   int a, b;
   cin >> a >> b;
   if (b == 0)
   {
      cout << "Impossible";
   }
   else
   {
      float r = a / float(b);
      cout << r;
   }
   cout << endl;

   return 0;

}
