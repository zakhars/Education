#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border)
{
    const auto bounds = numbers.equal_range(border);
    if (bounds.first != end(numbers) && *bounds.first == border) // found exact element
    {
        return bounds.first;
    }
    
    if (bounds.first == begin(numbers))
    {
        return begin(numbers);
    }

    if (bounds.second == end(numbers))
    {
        return prev(end(numbers));
    }
    if (border - *prev(bounds.first) <= *bounds.second - border)
    {
        return prev(bounds.first);
    }
    return bounds.second;
}

int main_cppy_w4_t8() {
    set<int> numbers = { 1, 4, 6 };
    cout <<
        *FindNearestElement(numbers, 0) << " " <<
        *FindNearestElement(numbers, 3) << " " <<
        *FindNearestElement(numbers, 5) << " " <<
        *FindNearestElement(numbers, 6) << " " <<
        *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}

// Teacher's solution:

/*
set<int>::const_iterator FindNearestElement(const set<int>& numbers,
                                            int border) {
  // ����������� �������� �� ������ �������, �� ������� border;
  // ���� ������ �������� ���, �� �� ������� numbers.end()
  // set::lower_bound ->
  // http://ru.cppreference.com/w/cpp/container/set/lower_bound
  const auto first_not_less = numbers.lower_bound(border);

  // ���� ��������� ����� ��� �� ������� �������� �� ������ border
  // ��� ���������, �� �� ��� �������� �����
  if (first_not_less == numbers.begin()) {
    return first_not_less;
  }

  // ���� ���������, �� ������� border, ��� � set �� ����, �� ���������� �����
  // �������� �� ��������� �������, ������� border
  // prev -> http://ru.cppreference.com/w/cpp/iterator/prev
  const auto last_less = prev(first_not_less);
  if (first_not_less == numbers.end()) {
    return last_less;
  }

  // ���������� ��� ���������-��������� � ������� ���,
  // ��� ������� ����� � ��������
  const bool is_left = (border - *last_less <= *first_not_less - border);
  return is_left ? last_less : first_not_less;
}

*/