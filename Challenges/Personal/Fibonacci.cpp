#include <iostream>
#include "Common/Timer.h"

int fib(int n)
{
   if (n < 0) return 0;
   if (n < 2) return n;
   return fib(n - 1) + fib(n - 2);
}

int main()
{
   common::timer t;
   for (volatile int i = 0; i < 100000; ++i)
   {
      fib(10);
   }
   std::cout << std::endl << "Duration is: " << t.us() << " microseconds" << std::endl;
   return 0;
}