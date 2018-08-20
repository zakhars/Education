#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) do { out << (x) << endl; out << (y) << endl; } while(0)

int main_cppr_w1_t5() {
    TestRunner tr;
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example");
    return 0;
}

// Teacher's solution

#define PRINT_VALUES1(out, x, y) out << (x) << endl << (y) << endl
