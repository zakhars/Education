#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

namespace

{

    template <class T>
    ostream& operator << (ostream& os, const vector<T>& s) {
        os << "{";
        bool first = true;
        for (const auto& x : s) {
            if (!first) {
                os << ", ";
            }
            first = false;
            os << x;
        }
        return os << "}";
    }

    template <class T>
    ostream& operator << (ostream& os, const set<T>& s) {
        os << "{";
        bool first = true;
        for (const auto& x : s) {
            if (!first) {
                os << ", ";
            }
            first = false;
            os << x;
        }
        return os << "}";
    }

    template <class K, class V>
    ostream& operator << (ostream& os, const map<K, V>& m) {
        os << "{";
        bool first = true;
        for (const auto& kv : m) {
            if (!first) {
                os << ", ";
            }
            first = false;
            os << kv.first << ": " << kv.second;
        }
        return os << "}";
    }

    template<class T, class U>
    void AssertEqual(const T& t, const U& u, const string& hint = {}) {
        if (t != u) {
            ostringstream os;
            os << "Assertion failed: " << t << " != " << u;
            if (!hint.empty()) {
                os << " hint: " << hint;
            }
            throw runtime_error(os.str());
        }
    }

    void Assert(bool b, const string& hint) {
        AssertEqual(b, true, hint);
    }

    class TestRunner {
    public:
        template <class TestFunc>
        void RunTest(TestFunc func, const string& test_name) {
            try {
                func();
                cerr << test_name << " OK" << endl;
            }
            catch (exception& e) {
                ++fail_count;
                cerr << test_name << " fail: " << e.what() << endl;
            }
            catch (...) {
                ++fail_count;
                cerr << "Unknown exception caught" << endl;
            }
        }

        ~TestRunner() {
            if (fail_count > 0) {
                cerr << fail_count << " unit tests failed. Terminate" << endl;
                exit(1);
            }
        }

    private:
        int fail_count = 0;
    };

    int NOD(int a, int b)
    {
        if (a < b) swap(a, b);

        while (b > 0)
        {
            int r = a % b;
            if (r == 0) return b;
            a = b;
            b = r;
        }

        return 0;
    }

}


class Rational {
public:
    Rational()
        : numerator(0),
        denominator(1)
    {
    }

    Rational(int numerator_, int denominator_)
        : numerator(numerator_),
        denominator(denominator_)
    {
        if (numerator == 0)
            denominator = 1;
        else
        {
            int nod = NOD(abs(numerator), abs(denominator));
            numerator /= nod;
            denominator /= nod;
            if (numerator < 0 && denominator < 0 ||
                numerator > 0 && denominator < 0)
            {
                numerator = -numerator;
                denominator = -denominator;
            }
        }
    }

    int Numerator() const
    {
        return numerator;
    }

    int Denominator() const
    {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

void TestDefault()
{
    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestPositiveNoReduction()
{
    Rational r(2,3);
    AssertEqual(r.Numerator(), 2);
    AssertEqual(r.Denominator(), 3);
}

void TestPositiveReduction()
{
    Rational r(2, 4);
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 2);
}

void TestNegativeNoReduction()
{
    Rational r1(2, -3);
    AssertEqual(r1.Numerator(), -2);
    AssertEqual(r1.Denominator(), 3);
    Rational r2(-2, 3);
    AssertEqual(r2.Numerator(), -2);
    AssertEqual(r2.Denominator(), 3);
    Rational r3(-2, -3);
    AssertEqual(r3.Numerator(), 2);
    AssertEqual(r3.Denominator(), 3);
}

void TestNegativeReduction()
{
    Rational r1(4, -6);
    AssertEqual(r1.Numerator(), -2);
    AssertEqual(r1.Denominator(), 3);
}

void TestZero()
{
    Rational r1(0, 1);
    AssertEqual(r1.Numerator(), 0);
    AssertEqual(r1.Denominator(), 1);
    Rational r2(0, 4);
    AssertEqual(r2.Numerator(), 0);
    AssertEqual(r2.Denominator(), 1);
}


int main_cppy_w02_t04() {
    TestRunner runner;
    runner.RunTest(TestDefault, "TestDefault");
    runner.RunTest(TestPositiveNoReduction, "TestPositiveNoReduction");
    runner.RunTest(TestPositiveReduction, "TestPositiveReduction");
    runner.RunTest(TestNegativeNoReduction, "TestNegativeNoReduction");
    runner.RunTest(TestNegativeReduction, "TestNegativeReduction");
    runner.RunTest(TestZero, "TestZero");
    return 0;
}

// Teacher's solution

/*
void TestPredefined() 
{
  AssertEqual(Rational(1, 1).Numerator(), 1, "Canonical form of 1/1 is 1/1");
  AssertEqual(Rational(1, 1).Denominator(), 1, "Canonical form of 1/1 is 1/1");
  AssertEqual(Rational(3, 5).Numerator(), 3, "Canonical form of 3/5 is 3/5");
  AssertEqual(Rational(3, 5).Denominator(), 5, "Canonical form of 3/5 is 3/5");
  AssertEqual(Rational(2147483647, 2147483647).Numerator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
  AssertEqual(Rational(2147483647, 2147483647).Denominator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
  AssertEqual(Rational(-5, 4).Numerator(), -5, "Canonical form of -5/4 is -5/4");
  AssertEqual(Rational(-5, 4).Denominator(), 4, "Canonical form of -5/4 is -5/4");
  AssertEqual(Rational(5, -4).Numerator(), -5, "Canonical form of 5/-4 is -5/4");
  AssertEqual(Rational(5, -4).Denominator(), 4, "Canonical form of 5/-4 is -5/4");
  AssertEqual(Rational(-6, -2).Numerator(), 3, "Canonical form of -6/-2 is 3/1");
  AssertEqual(Rational(-6, -2).Denominator(), 1, "Canonical form of -6/-2 is 3/1");
  AssertEqual(Rational(21, 56).Numerator(), 3, "Canonical form of 21/56 is 3/8");
  AssertEqual(Rational(21, 56).Denominator(), 8, "Canonical form of 21/56 is 3/8");
  AssertEqual(Rational(0, 100).Numerator(), 0, "Canonical form of 0/100 is 0/1");
  AssertEqual(Rational(0, 100).Denominator(), 1, "Canonical form of 0/100 is 0/1");
  AssertEqual(Rational().Numerator(), 0, "Canonical form of default constructed is 0/1");
  AssertEqual(Rational().Denominator(), 1, "Canonical form of default constructed is 0/1");
}
*/