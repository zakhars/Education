#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>


#include "Challenges/Hackerrank/CTCI.h"
#include "Challenges/Hackerrank/Cpp.h"
#include "common/Timer.h"
#include "common/Random.h"
#include "common/Utils.h"


using namespace std;
using namespace hrnk::ctci;


//int main()
//{
//}


int main()
{
   common::rand_int rnd;
   vector<int> v(1000000);
   generate(begin(v), end(v), rnd);
   string input = common::to_string(v);

   common::timer t;
   //array_left_rotation::run(array_left_rotation::solution, v, false);
   //array_left_rotation::run(array_left_rotation::solution_orig, false);
   cout << "duration is " << t.get_duration_us() << " us" << endl;
   return 0;
}

