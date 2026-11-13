#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <tuple>
using namespace std;

int main_cpp_y_w1_t2()
{
   size_t n, density;
   cin >> n >> density;
   
   uint64_t weight_total = 0;
   uint64_t w, h, d;
   for (size_t i = 0; i < n; ++i)
   {
      cin >> w >> h >> d;
      weight_total += w * h * d * density;
   }

   cout << weight_total << endl;

   return 0;
}


// Teacher's solution
/*

int main() {
   int N, R;
   cin >> N >> R;
   uint64_t answer = 0;
   for (int i = 0; i < N; ++i) 
   {
      int W, H, D;
      cin >> W >> H >> D;
      // ≈сли не привести W к типу uint64_t перед умножением,
      // произведение будет иметь тип int и случитс€ переполнение.
      // јльтернативное решение Ч хранить сами W, H, D в uint64_t
      answer += static_cast<uint64_t>(W) * H * D;
      }
   answer *= R;
   cout << answer << endl;
   return 0;
}

*/