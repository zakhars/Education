#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintPermutations(int num1, int num2)
{
    int count = num2 - num1 + 1;
    vector<int> v(count);
    for (int i = 0; i < count; ++i)
    {
        v[i] = num2--;
    }

    do
    {
        for (auto vi : v)
        {
            cout << vi << " ";
        }
        cout << endl;
    } while (prev_permutation(begin(v), end(v)));

}

int main_cppy_w4_t5()
{
    int num1 = 1;
    int num2;
    cin >> num2;
    PrintPermutations(num1, num2);
    return 0;
}

// Teacher's solution

/*
int main() 
{
  int range_length;
  cin >> range_length;
  vector<int> permutation(range_length);
  
  // iota             -> http://ru.cppreference.com/w/cpp/algorithm/iota
  // «аполн€ет диапазон последовательно возрастающими значени€ми
  iota(permutation.begin(), permutation.end(), 1);
  
  // reverse          -> http://ru.cppreference.com/w/cpp/algorithm/reverse
  // ћен€ет пор€док следовани€ элементов в диапазоне на противоположный
  reverse(permutation.begin(), permutation.end());
  
  // prev_permutation ->
  //     http://ru.cppreference.com/w/cpp/algorithm/prev_permutation
  // ѕреобразует диапазон в предыдущую (лексикографически) перестановку,
  // если она существует, и возвращает true,
  // иначе (если не существует) - в последнюю (наибольшую) и возвращает false
  do {
    for (int num : permutation) {
      cout << num << ' ';
    }
    cout << endl;
  } while (prev_permutation(permutation.begin(), permutation.end()));

  return 0;
}

*/