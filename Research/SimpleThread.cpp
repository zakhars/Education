#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <thread>
#include <iostream>
#include "common/timer.h"

namespace mt
{
   using namespace std;
   const unsigned CP = 300000000;

   void worker(const vector<int>& v, unsigned part, unsigned of)
   {
      int pos1 = part * (CP / of);
      int pos2 = (part + 1) * (CP / of) - 1;
      cout << accumulate(cbegin(v) + pos1, cbegin(v) + pos2 + 1, 0) << endl;
   }

   void parallel_calc(const vector<int>& v, unsigned numthreads)
   {
      vector<thread> vt;

      for (unsigned i = 0; i < numthreads; ++i)
      {
         vt.push_back(thread(worker, ref(v), i, numthreads));
      }

      for_each(begin(vt), end(vt), mem_fn(&thread::join));
   }

   void sequential_calc(const vector<int>& v, unsigned numthreads)
   {
      for (unsigned i = 0; i < numthreads; ++i)
      {
         worker(v, i, numthreads);
      }
   }

}