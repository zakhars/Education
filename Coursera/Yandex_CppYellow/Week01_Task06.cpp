#include <map>
#include <iostream>

using namespace std;

template<typename Key, typename Val>
Val& GetRefStrict(map<Key, Val>& m, Key k)
{
	auto pval = m.find(k);
	if (pval == m.end())
	{
		throw runtime_error("Key not found");
	}
	return pval->second;
}

/*
int main()
{
	try
	{
		map<int, int> m = { {1,2},{2,4} };
		auto vr = GetRefStrict(m, 1);
		cout << vr;
		vr = 8;
	}
	catch (runtime_error&)
	{
		cout << "exception\n";
	}
}
*/

// Teacher's solution

/*
#include <map>
#include <stdexcept>

template<typename KeyType, typename ValueType>
ValueType& GetRefStrict(map<KeyType, ValueType>& input_map, KeyType key) {
	if (input_map.count(key) == 0) {
		throw runtime_error("no such key in dictionary");
	}
	return input_map[key];
}
*/