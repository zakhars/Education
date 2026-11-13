#include <iostream>

int reverse(int x) {
   
   if (x == -2147483648) return 0;

   int sign = x < 0 ? -1 : 1;
   x = abs(x);
   int xc = x;
   int dc = 0;
   while (xc > 0)
   {
      xc /= 10;
      dc++;
   }

   int res = 0;
   dc--;
   while (dc >= 0)
   {
      int digit = x % 10;
      x /= 10;

      if (digit > 2 && (int)pow(10, dc) == 1e9) return 0;

      if (res + digit * (int)pow(10, dc) < res) return 0;

      res += digit * (int)pow(10, dc);
      dc--;
   }
   return sign * res;
}


int main()
{

   int reversed = reverse(1563847412);
   std::cout << reversed;
}

