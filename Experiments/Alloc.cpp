#include <vector>
#include <iostream>
#include <chrono>

// 32 bit
// Opt 55
// LTCG 57
// Default 78

void StlAllocDealloc()
{
   for (int i = 0; i < 1000; i++)
   {
      std::vector<int> v;
      for (int j = 0; j < 10000000; j++)
         v.push_back(j ^ i);
   }
}

void StlAllocDeallocMeasure()
{
   using Clock = std::chrono::high_resolution_clock;

   auto t1 = Clock::now();

   StlAllocDealloc();

   auto t2 = Clock::now();

   std::cout << "Delta: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
}

const int CAPACITY = 100000000;

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


/*
void StlAllocDeallocTbb()
{
   for (int i = 0; i < 1000; i++)
   {
      std::vector<int, tbb::scalable_allocator<int>> v;
      std::vector<int> v;
      for (int j = 0; j < 10000000; j++)
         v.push_back(j ^ i);
   }
}

void StlAllocDeallocTbbMeasure()
{
   FIX8::stop_watch::init();
   FIX8::stop_watch sw(1);

   StlAllocDeallocTbb();

   std::cout << "Delta: " << sw.val(1) << std::endl;
}
*/
