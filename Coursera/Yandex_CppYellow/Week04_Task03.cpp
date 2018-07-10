#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<string> res;
    auto it1 = begin(s);

    while (it1 != end(s))
    {
        auto it2 = find(it1, end(s), ' ');
        string word(it1, it2);
        res.push_back(word);
        if (it2 != end(s))
        {
            ++it2;
        }
        it1 = it2;
    }

    return res;
}

int main_cppy_w4_t3() 
{
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}

// Teacher's solution:

/*
vector<string> SplitIntoWords(const string& str) {
  // ������� ������, � ������� ����� ��������� �����
  vector<string> result;

  // ��� ��� ��������� ����� ������������ ������� �� �������� ����� ������
  // str_begin ����� ��������� ������
  auto str_begin = begin(str);
  // str_end ������ ����� ��������� �� ����� ������ (������� �� �����������)
  const auto str_end = end(str);

  // � ����� ��� ������� ����������, ��� ��� ������������ ������ ��������� ��� �
  // ������� break
  while (true) {
    
    // ������� ������ ������ � ������� ������� ������
    auto it = find(str_begin, str_end, ' ');
    
    // ������������ [str_begin, it) � ��������� �����
    result.push_back(string(str_begin, it));
    
    if (it == str_end) {
      // ���� �������� ������ ���, ���� ���� ���������.
      // ��������� ����� ��� ���������
      break;
    } else {
      // ����� ������ ������ ����� ������� � ������ ���������� �����.
      // ���� � �������� str_begin
      str_begin = it + 1;
    }
    
  }

  return result;
}
*/