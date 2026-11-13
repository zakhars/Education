#include <set>
#include <iostream>
#include <string>
using namespace std;

int main_02_15()
{
	int n;
	cin >> n;
	set<string> words;
	for(int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		words.insert(word);
	}
	cout << words.size() << endl;

	return 0;
}
