#include <tuple>
#include <string>
#include <map>
#include <functional>

/*
using namespace std;
namespace map_custom_compare
{
   struct dbl_less : public binary_function<double, double, bool>
   {
      bool operator()(const double& lhs, const double& rhs) const
      {
         return lhs < rhs;
      }
   } dblless;
   struct dbl_gt : public binary_function<double, double, bool>
   {
      bool operator()(const double& lhs, const double& rhs) const
      {
         return lhs >= rhs;
      }
   } dblgt;
   map<double, double, binary_function<double, double, bool>> md1(dblless);
   map<double, double, binary_function<double, double, bool>> md2(dblgt);
   void f1(map<double, double, binary_function<double, double, bool>>) {}
}

tuple<const int&, const string&, const int&> f1()
{
   // There is no copying here:
   int a;
   int b;
   return tie(a, "s", b);
   // However make_tuple creates tuple from copy
}

void f2()
{
   const map<string, int> dict{ {"s", 1} };
   //const auto elem = dict[0]; // fails
   const auto elem = dict.at(0); // const method
}

void f3()
{
   bool success;
   string s_result;

   auto get_some_tuple = [] { return std::make_tuple<bool, string>(true, "success"); };

   tie(success, s_result) = get_some_tuple();
}
*/