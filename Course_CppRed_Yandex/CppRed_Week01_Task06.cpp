#include <string>
#include <vector>
using namespace std;

#define MERGE_PARTS(x,y)  x ## y
#define MERGE_PARTS2(x,y)  MERGE_PARTS(x,y)
#define UNIQ_ID MERGE_PARTS2(var, __LINE__)
   

int main_cppr_w1_t6() {
    int UNIQ_ID = 0;
    string UNIQ_ID = "hello";
    vector<string> UNIQ_ID = { "hello", "world" };
    vector<int> UNIQ_ID = { 1, 2, 3, 4 };
    return 0;
}

// Teacher's solution:

#define UNIQ_ID_IMPL_2(lineno) _a_local_var_##lineno
#define UNIQ_ID_IMPL(lineno) UNIQ_ID_IMPL_2(lineno)
#define UNIQ_ID1 UNIQ_ID_IMPL(__LINE__)