#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <windows.h>

#include "Common/Timer.h"

namespace perf
{
   using namespace std;

void RealSleep()
{
   DWORD start = ::GetTickCount();
   for (long i = 0; i < 500; ++i)
   {
      ::Sleep(1);
   }
   std::cout << "Sleep(1) actually means " << (::GetTickCount() - start) / 500.0 << " msecs" << std::endl;
}

   void SoringPerformance()
   {
      const int SIZE = 100000;
      vector<int> v;
      srand(unsigned(time(0)));
      for (int i = 0; i < SIZE; i++)
      {
         //v.push_back(std::rand());
         v.push_back(1);
      }

      common::timer t;
      //BubbleSort(v);
      cout << endl << "Duration is: " << t.get_duration_us() << " microseconds" << endl;

      t.save_time();
      sort(begin(v), end(v));
      cout << endl << "Duration is: " << t.get_duration_us() << " microseconds" << endl;

      t.save_time();
      stable_sort(begin(v), end(v));
      cout << endl << "Duration is: " << t.get_duration_us() << " microseconds" << endl;
   }

   void MeasureHashPerf()
   {
      const int SIZE = 1048575;

      std::unordered_map<std::string, int> hash;

      for (int i = 0; i < SIZE; i++)
      {
         hash.insert(std::make_pair(std::to_string(i), i));
      }

      std::cout << "Bucket count: " << hash.bucket_count() << std::endl;

      std::vector<std::string> keys(SIZE);
      for (int i = 0; i < SIZE; i++)
      {
         keys[i] = std::to_string(i);
      }

      volatile int val;
      std::string sval;
      std::string singleval = "15000";

      auto t0 = std::chrono::high_resolution_clock::now();

      for (volatile int i = 0; i < SIZE; i++)
      {
      }

      auto t1 = std::chrono::high_resolution_clock::now();
      auto loop_dur = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();


      t0 = std::chrono::high_resolution_clock::now();

      for (int i = 0; i < SIZE; i++)
      {
         val = hash[singleval];
      }

      t1 = std::chrono::high_resolution_clock::now();

      std::cout << (std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() - loop_dur) * 1.0 / SIZE << " microseconds" << std::endl;
   }

   const int CAPACITY = 10000000;

   // 32 bit
   // Opt 55
   // LTCG 57
   // Default 78

   void StlAllocDealloc()
   {
      for (int i = 0; i < 1000; i++)
      {
         std::vector<int> v;
         //std::vector<int, tbb::scalable_allocator<int>> v;
         for (int j = 0; j < CAPACITY; j++)
            v.push_back(j ^ i);
      }
   }

   void StlAllocDeallocMeasure()
   {
      //FIX8::stop_watch::init();
      //FIX8::stop_watch sw(1);

      using Clock = std::chrono::high_resolution_clock;

      auto t1 = Clock::now();

      StlAllocDealloc();

      auto t2 = Clock::now();

      std::cout << "Delta: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
      //std::cout << "Delta: " << sw.val(1) << std::endl;
   }

   void FillArray(int* buffer)
   {
      for (int i = 0; i < 1000; i++)
      {
         for (int j = 0; j < CAPACITY; j++)
            buffer[j] = i ^ j;
      }
   }

   void PrintTime()
   {
      time_t rawtime;
      struct tm timeinfo;
      time(&rawtime);
      localtime_s(&timeinfo, &rawtime);
      #pragma warning (disable:4996)
      printf("%s", asctime(&timeinfo));
   }

   void FillArrayMeasure()
   {
      int* buffer = new int[CAPACITY];
      PrintTime();
      FillArray(buffer);
      PrintTime();
      std::printf("%d\n", buffer[25]);
      delete[] buffer;
   }

}