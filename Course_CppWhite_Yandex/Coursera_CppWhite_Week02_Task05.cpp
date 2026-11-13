#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& a, vector<string>& b)
{
   b.insert(end(b), begin(a), end(a));
   a.clear();
}
