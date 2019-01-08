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


int main_main()
{

   common::timer t;
   //string input = array_left_rotation::gen_input();
   //array_left_rotation::run(array_left_rotation::solution, input, false);

   string input = anagrams::gen_input();
   //anagrams::run(anagrams::solution, input, false);

   cout << "Duration is " << t.us() << " us" << endl;

   return 0;
}

