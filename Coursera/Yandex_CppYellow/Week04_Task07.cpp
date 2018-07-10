#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin <= 1) return;
    vector<typename RandomIt::value_type> v{range_begin, range_end};
    auto middle = begin(v) + (end(v)- begin(v)) / 2;
    MergeSort(begin(v), middle);
    MergeSort(middle, end(v));
    merge(begin(v), middle, middle, end(v), range_begin);
}

template <typename RandomIt>
void MergeSort3(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin <= 1) return;
    vector<typename RandomIt::value_type> v{ range_begin, range_end };
    auto range1_end = begin(v) + (end(v) - begin(v)) / 3;
    auto range2_end = begin(v) + 2 * (end(v) - begin(v)) / 3;
    MergeSort3(begin(v), range1_end);
    MergeSort3(range1_end, range2_end);
    MergeSort3(range2_end, end(v));
    vector<typename RandomIt::value_type> vt;
    merge(begin(v), range1_end, range1_end, range2_end, back_inserter(vt));
    merge(begin(vt), end(vt), range2_end, end(v), range_begin);
}


int main_cppy_w4_t7()
{
    vector<int> v{4,5,3,7,1,8,6,9,4,3,2,0,1,3,4,7,3,8};
    MergeSort(begin(v), end(v));
    for (auto vi : v)
    {
        cout << vi << " ";
    }
    cout << endl;

    vector<int> v2{ 4,5,3,7,1,8,6,9,4,3,2,0,1,3,4,7,3};
    MergeSort3(begin(v2), end(v2));
    for (auto vi : v2)
    {
        cout << vi << " ";
    }
    cout << endl;

    return 0;
}

// Teacher's solution

/*
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  // 1. ���� �������� �������� ������ 2 ���������, ������� �� �������
  int range_length = range_end - range_begin;
  if (range_length < 2) {
    return;
  }
  
  // 2. ������� ������, ���������� ��� �������� �������� ���������
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  
  // 3. ��������� ������ �� ��� ������ �����
  auto mid = elements.begin() + range_length / 2;
  
  // 4. �������� ������� MergeSort �� ������ �������� �������
  MergeSort(elements.begin(), mid);
  MergeSort(mid, elements.end());
  
  // 5. � ������� ��������� merge ������� ��������������� ��������
  // � �������� ��������
  // merge -> http://ru.cppreference.com/w/cpp/algorithm/merge
  merge(elements.begin(), mid, mid, elements.end(), range_begin);
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  // 1. ���� �������� �������� ������ 2 ���������, ������� �� �������
  int range_length = range_end - range_begin;
  if (range_length < 2) {
    return;
  }
  
  // 2. ������� ������, ���������� ��� �������� �������� ���������
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  
  // 3. ��������� ������ �� ��� ������ �����
  auto one_third = elements.begin() + range_length / 3;
  auto two_third = elements.begin() + range_length * 2 / 3;
  
  // 4. �������� ������� MergeSort �� ������ ����� �������
  MergeSort(elements.begin(), one_third);
  MergeSort(one_third, two_third);
  MergeSort(two_third, elements.end());
  
  // 5. � ������� ��������� merge c������ ������ ��� ����� �� ��������� ������
  // back_inserter -> http://ru.cppreference.com/w/cpp/iterator/back_inserter
  vector<typename RandomIt::value_type> interim_result;
  merge(elements.begin(), one_third, one_third, two_third,
        back_inserter(interim_result));
  
  // 6. � ������� ��������� merge ������� ��������������� �����
  // � �������� ��������
  // merge -> http://ru.cppreference.com/w/cpp/algorithm/merge
  merge(interim_result.begin(), interim_result.end(), two_third, elements.end(),
        range_begin);
}
*/