#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void PrintVectorPart(const vector<int>& numbers)
{
    auto it = find_if(begin(numbers), end(numbers), [](int val) { return val < 0; });

    for (auto i = vector<int>::const_reverse_iterator(it); i != rend(numbers); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main_cppy_w4_t1()
{
    PrintVectorPart({ 6, 1, 8, -5, 4 });
    PrintVectorPart({ -6, 1, 8, -5, 4 });
    PrintVectorPart({ 6, 1, 8, 5, 4 });
    return 0;
}

// Teacher's solution

/*
void PrintVectorPart(const vector<int>& numbers) {
  auto negative_it = find_if(
    numbers.begin(), numbers.end(),
    [](int number) {
      return number < 0;
    }
  );

  for (auto it = negative_it; it != numbers.begin(); ) {
    cout << *(--it) << " ";
  }
}
*/