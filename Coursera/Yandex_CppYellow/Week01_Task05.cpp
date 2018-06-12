#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T> T Sqr(T val);
template<typename first, typename second> pair<first, second> Sqr(const pair<first, second>& p);
template<typename T> vector<T> Sqr(const vector<T>& v);
template<typename key, typename value> map<key, value> Sqr(const map<key, value>& m);

template<typename T>
T Sqr(T val)
{
   return val * val;
}

template<typename first, typename second>
pair<first, second> Sqr(const pair<first, second>& p)
{
   return make_pair(Sqr(p.first), Sqr(p.second));
}

template<typename T>
vector<T> Sqr(const vector<T>& v)
{
   vector<T> vr(v.size());
   for (size_t i = 0; i < v.size(); ++i)
   {
	   vr[i] = Sqr(v[i]);
   }
   return vr;
}

template<typename key, typename value>
map<key, value> Sqr(const map<key, value>& m)
{
   map<key, value> mr;
   for (const pair<key, value>& mi : m)
   {
      mr.insert(make_pair(mi.first, Sqr(mi.second)));
   }
   return mr;
}

/*
//int main_cpp_yellow_week01_task05()
int main()
{
   vector<int> v = { 1, 2, 3 };
   cout << "vector:";
   for (int x : Sqr(v)) 
   {
      cout << ' ' << x;
   }
   cout << endl;

   map<int, pair<int, int>> map_of_pairs = 
   {
      { 4,{ 2, 2 } },
      { 7,{ 4, 3 } }
   };
   cout << "map of pairs:" << endl;
   for (const pair<int, pair<int, int>>& x : Sqr(map_of_pairs))
   {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
   }
   return 0;
}
*/

// Teacher's solution

/*
// Объявим функции без тела,
// чтобы их можно было использовать в произвольном порядке

// Для простых типов
template<typename T>
T Sqr(T value);

// Для вектора
template<typename T>
vector<T> Sqr(const vector<T>& value);

// Для словаря
template<typename K, typename V>
map<K, V> Sqr(const map<K, V>& value);

// Для пары
template<typename K, typename V>
pair<K, V> Sqr(const pair<K, V>& value);

// Теперь реализуем их в соответствии с заданием
template<typename T>
T Sqr(T value) {
	return value * value;
}

template<typename T>
vector<T> Sqr(const vector<T>& value) {
	vector<T> result;
	for (const T& x : value) {
		// Здесь важно, что вместо x * x вызывается функция Sqr:
		// это позволяет возводить в квадрат составные объекты
		result.push_back(Sqr(x));
	}

	return result;
}

template<typename K, typename V>
map<K, V> Sqr(const map<K, V>& value) {
	map<K, V> result;
	for (const auto& element : value) {
		result[element.first] = Sqr(element.second);
	}
	return result;
}

template<typename K, typename V>
pair<K, V> Sqr(const pair<K, V>& value) {
	return { Sqr(value.first), Sqr(value.second) };
}

*/