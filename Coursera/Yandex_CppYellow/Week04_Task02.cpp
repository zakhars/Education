#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Common/CppUT.h"

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
    vector<T> result;

    for (auto elem : elements)
    {
        if (elem > border)
        {
            result.push_back(elem);
        }
    }
    //sort(begin(result), end(result));

    return result;
}

void TestAll()
{
    AssertEqual(FindGreaterElements(set<string>{"C", "C++"}, string("Python")), vector<string>{});
    AssertEqual(FindGreaterElements(set<string>{"Python", "C", "C++"}, string("A")), vector<string>{"C", "C++", "Python"});
    AssertEqual(FindGreaterElements(set<int>{1, 5, 7}, 0), vector<int>{1, 5, 7});
    AssertEqual(FindGreaterElements(set<int>{1, 5, 7}, 1), vector<int>{5, 7});
    AssertEqual(FindGreaterElements(set<int>{7, 1, 5}, 1), vector<int>{5, 7});
    AssertEqual(FindGreaterElements(set<int>{1, 5, 7}, 5), vector<int>{7});
    AssertEqual(FindGreaterElements(set<int>{1, 5, 7}, 7), vector<int>{});
    AssertEqual(FindGreaterElements(set<int>{1, 5, 7}, 8), vector<int>{});
    AssertEqual(FindGreaterElements(set<int>{1, 5}, 0), vector<int>{1, 5});
    AssertEqual(FindGreaterElements(set<int>{1, 5}, 1), vector<int>{5});
    AssertEqual(FindGreaterElements(set<int>{1, 5}, 5), vector<int>{});
    AssertEqual(FindGreaterElements(set<int>{1, 5}, 6), vector<int>{});
    AssertEqual(FindGreaterElements(set<int>{1}, 0), vector<int>{1});
    AssertEqual(FindGreaterElements(set<int>{1}, 1), vector<int>{});
    AssertEqual(FindGreaterElements(set<int>{1}, 2), vector<int>{});
    AssertEqual(FindGreaterElements(set<int>{}, 1), vector<int>{});
}

int main_cppy_w4_t2() 
{
    TestRunner runner;
    runner.RunTest(TestAll, "TestAll");
    return 0;
}

// Teacher's solution:
/*
template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    // Начнём итерироваться по множеству
    auto it = begin(elements);
    // Цель — найти первый элемент, больший border
    // Если итератор не достиг конца и указывает не туда, двигаем
    while (it != end(elements) && *it <= border) {
        ++it;
    }
    // Возвращаем вектор, созданный из элементов множества, начиная с it
    return { it, end(elements) };
}*/