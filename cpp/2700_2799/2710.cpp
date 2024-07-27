#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// here
class Solution {
public:
  string removeTrailingZeros(string num) {

    auto pos =
        find_if(num.rbegin(), num.rend(), [](char p) { return p != '0'; }) -
        num.rbegin();

    num.resize(num.size() - pos);
    return num;
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {}
  {}
}
#endif
