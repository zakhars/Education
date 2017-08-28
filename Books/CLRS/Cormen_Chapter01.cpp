#include <iomanip>
#include <vector>
#include <functional>
#include <iostream>

namespace cormen
{

namespace ch01
{
   using namespace std;
   using durations = vector<pair<string, int64_t>>;
   durations DurationsUS
   {
      { "Msecond",   1000 },
      { "Second",    1000000 },
      { "Minute",    60000000 },
      { "Hour",      3600000000 },
      { "Day",       86400000000 },
      { "Month",     2592000000000 },
      { "Year",      31536000000000 },
      { "Century",   3153600000000000 },
      { "Epoch",     31536000000000000 }
   };

   using inv_fun = pair<string, function<double(double)>>;

   vector<inv_fun> Functions
   {
      { "logn", [](double t_us) { return pow(2, t_us); } },
      { "sqrtn",[](double t_us) { return pow(t_us, 2); } },
      { "n",    [](double t_us) { return t_us; } },
      { "nlogn",[](double t_us) { double n1 = t_us; double n2 = t_us / log2(n1); while (fabs(n2 - n1) > 1) { n1 = n2; n2 = t_us / log2(n1); } return n2 <= 0 ? 1 : n2; } },
      { "n2",   [](double t_us) { return pow(t_us, 0.5); } },
      { "n3",   [](double t_us) { return pow(t_us, 1 / 3.0); } },
      { "2pown",[](double t_us) { return log2(t_us); } },
      { "nfact",[](double t_us) { double nf = t_us / 2; int i = 3; for (; nf >= 1; i++) { nf /= i; } return t_us < 3 ? 0 : i; } }
   };

   void CalcMaxN()
   {
      const int w = 7;

      cout << setw(w) << " ";
      for (const auto& dur : DurationsUS)
      {
         cout << setw(w) << dur.first.c_str() << " ";
      }
      for (auto fun : Functions)
      {
         cout << endl << setw(w) << fun.first.c_str();
         for (const auto& dur : DurationsUS)
            cout << setw(w) << setprecision(2) << fun.second(static_cast<double>(dur.second)) << " ";
      }
      cout << endl;
   }

} // ch1

} // cormen