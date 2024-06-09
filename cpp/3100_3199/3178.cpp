#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#ifdef LEETCODE
#include "../parse.h"
#endif

// jj
class Solution {
public:
  int numberOfChild(int n, int k) {
    int loop = k / (n - 1);
    int left = k % (n - 1);

    if (loop % 2 == 0) {
      return left;
    }
    return n - 1 - left;
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
