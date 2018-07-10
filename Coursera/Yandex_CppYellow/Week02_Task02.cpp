#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include "Common/CppUT.h"

using namespace std;

int GetDistinctRealRootCount(double a, double b, double c) 
{
    if (a == 0)
    {
        if (b != 0)
        {
            return 1;
        }
        return 0;
    }
    double D = b * b - 4 * a * c;
    if (D >= 0)
    {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        return x1 == x2 ? 1 : 2;
    }
    return 0;
}

void Test2Roots()
{
    AssertEqual(GetDistinctRealRootCount(4, 30, 4), 2);
}
void Test1Root()
{
    AssertEqual(GetDistinctRealRootCount(0, 3, 4), 1);
    AssertEqual(GetDistinctRealRootCount(4, 0, 0), 1);
    AssertEqual(GetDistinctRealRootCount(4, 4, 1), 1);
    AssertEqual(GetDistinctRealRootCount(2, 4, 2), 1);
}
void Test0Roots()
{
    AssertEqual(GetDistinctRealRootCount(4, 3, 4), 0);
    AssertEqual(GetDistinctRealRootCount(4, 0, 4), 0);
    AssertEqual(GetDistinctRealRootCount(0, 0, 4), 0);
}

void AllTests()
{
    TestRunner runner;
    runner.RunTest(Test2Roots, "Test2Roots");
    runner.RunTest(Test1Root,  "Test1Root");
    runner.RunTest(Test0Roots, "Test0Roots");
}

int main_cppy_w02_t02() 
{
    AllTests();

    return 0;
}


// Teacher's solution

/*
void TestRootCount() {
  mt19937 gen;
  uniform_real_distribution<> unif(-10, 10);

  for (auto i = 0; i < 100; ++i) {
    const auto a = unif(gen);
    const auto b = unif(gen);
    const auto c = unif(gen);

    const auto count = GetDistinctRealRootCount(a, b, c);

    Assert(count >= 0 && count <= 2,
           "Quadratic equation has only 0, 1 or 2 real roots.");
  }
}

void TestOneRoot() {
  mt19937 gen;
  uniform_real_distribution<> unif(-10, 10);

  for (auto i = 0; i < 100; ++i) {
    const auto x_1 = unif(gen);

    const auto p = x_1 + x_1;
    const auto q = x_1 * x_1;

    const auto count = GetDistinctRealRootCount(1, p, q);
    stringstream description;
    description << showpos << "x^2" << p << "x" << q
                << " = 0 has 1 real root.";

    AssertEqual(count, 1, description.str());
  }
}

void TestNoRoots() {
  AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0,
              "x^2+1 = 0 has 0 real roots.");
  AssertEqual(GetDistinctRealRootCount(1, 3, 4), 0,
              "x^2+3x+4 = 0 has 0 real roots.");
  AssertEqual(GetDistinctRealRootCount(1, -2, 10), 0,
              "x^2-2x+10 = 0 has 0 real roots.");
}

void TestLinearEquation() {
  AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1,
              "2x+1 = 0 has 1 real roots.");
  AssertEqual(GetDistinctRealRootCount(0, -1, 0), 1,
              "-x = 0 has 0 real roots.");
  AssertEqual(GetDistinctRealRootCount(0, 120, -10), 1,
              "120x - 10 = 0 has 0 real roots.");
}

void TestConstant() {
  AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0,
              "c = 0, where c = 1 has 1 real roots.");
  AssertEqual(GetDistinctRealRootCount(0, 0, -10), 0,
              "c = 0, where c = -10 has 0 real roots.");
  AssertEqual(GetDistinctRealRootCount(0, 0, 189238910), 0,
              "c = 0, where c = 189238910 has 0 real roots.");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestRootCount, "TestRootCount");
  runner.RunTest(TestOneRoot, "TestOneRoot");
  runner.RunTest(TestNoRoots, "TestNoRoots");
  runner.RunTest(TestLinearEquation, "TestLinearEquation");
  runner.RunTest(TestConstant, "TestConstant");
  return 0;
}

*/