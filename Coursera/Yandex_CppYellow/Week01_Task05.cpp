#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T> T Sqr(T val);
template<typename first, typename second> pair<first, second> Sqr(pair<first, second>& p);
template<typename T> vector<T> Sqr(const vector<T>& v);
template<typename key, typename value> map<key, value> Sqr(const map<key, value>& m);

template<typename T>
T Sqr(T val)
{
   return val * val;
}

template<typename first, typename second>
pair<first, second> Sqr(pair<first, second>& p)
{
   return make_pair(Sqr(p.first), Sqr(p.second));
}

template<typename T>
vector<T> Sqr(const vector<T>& v)
{
   vector<T> vr;
   for (const T& vi : v)
   {
      vr.push_back(Sqr(vi));
   }
   return vr;
}

template<typename key, typename value>
map<key, value> Sqr(const map<key, value>& m)
{
   map<key, value> mr;
   for (const pair<key, value>& mi : m)
   {
      mr.insert(Sqr(mi));
   }
   return mr;
}


int main()
{
   vector<int> v = { 1, 2, 3 };
   cout << "vector:";
   for (int x : Sqr(v)) 
   {
      cout << ' ' << x;
   }
   cout << endl;

   /*map<int, pair<int, int>> map_of_pairs = 
   {
      { 4,{ 2, 2 } },
      { 7,{ 4, 3 } }
   };
   cout << "map of pairs:" << endl;
   for (const auto& x : Sqr(map_of_pairs)) 
   {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
   }*/
}