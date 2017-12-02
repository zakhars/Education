#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Challenges/Hackerrank/CTCI.h"
#include "Challenges/Hackerrank/Cpp.h"
#include "common/Timer.h"


using namespace std;
using namespace hrnk::ctci;


int main()
{
   common::timer t;
   for(int i = 0; i < 1000000; i++)
   {
      anagrams::run(anagrams::solution_orig, false);
   }
   cout << t.get_duration_us() << endl;

   return 0;
}

