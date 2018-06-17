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

    bool IsPalindrom(const string& s)
    {
        if (s.empty()) return true;
        size_t b = 0;
        size_t e = s.size() - 1;

        while (b < e)
        {
            if (s[b] != s[e]) return false;
            b++;
            e--;
        }
        return true;
    }
}

void TestPalindrom()
{
    Assert(IsPalindrom(""), "Empty");
    Assert(IsPalindrom(" "), "Space");
    Assert(IsPalindrom("a"), "Single");
    Assert(IsPalindrom("aa"), "Even");
    Assert(IsPalindrom("  "), "Even");
    Assert(IsPalindrom("abba"), "Even");
    Assert(IsPalindrom("aba"), "Odd");
    Assert(IsPalindrom("   "), "Odd");
    Assert(IsPalindrom("abdba"), "Odd");
    Assert(IsPalindrom(" abdba "), "Spaces both ends");
    Assert(IsPalindrom("a bb a"), "Spaces inside");
    Assert(IsPalindrom("a b b a"), "Spaces inside");
    Assert(!IsPalindrom("ab"), "Not palindrom1");
    Assert(!IsPalindrom("bdba"), "Not palindrom2");
    Assert(!IsPalindrom("abdba "), "Trailing space");
    Assert(!IsPalindrom(" abdba"), "Leading space");
    Assert(!IsPalindrom("a bb  a"), "Spaces inside");
    Assert(!IsPalindrom("abdqwdba"), "Not palindrom3");
}

int main_cppy_w02_t05() {
    TestRunner runner;
    runner.RunTest(TestPalindrom, "TestPalindrom");

    return 0;
}

// Teacher's solution

/*
void TestIsPalindrom() {
  Assert(IsPalindrom(""), "empty string is a palindrome");
  Assert(IsPalindrom("a"), "one letter string is a palindrome");
  Assert(IsPalindrom("abba"), "abba is a palindrome");
  Assert(IsPalindrom("abXba"), "abXba is a palindrome");
  Assert(IsPalindrom("a b X b a"), "`a b X b a` is a palindrome");
  Assert(IsPalindrom("  ABBA  "), "`  ABBA  ` is a palindrome");

  Assert(!IsPalindrom("XabbaY"), "XabbaY is not a palindrome");
  Assert(!IsPalindrom("abXYba"), "abXYba is not a palindrome");
  Assert(!IsPalindrom("Xabba"), "Xabba is not a palindrome");
  Assert(!IsPalindrom("abbaX"), "abbaX is not a palindrome");
  Assert(
    !IsPalindrom("was it a car or a cat i saw"),
    "`was it a car or a cat i saw` is not a palindrome because spaces do not match"
  );
  Assert(!IsPalindrom("ABBA   "), "`ABBA   ` is not a palindrome");
  Assert(!IsPalindrom("  ABBA"), "`  ABBA` is not a palindrome");
}

*/