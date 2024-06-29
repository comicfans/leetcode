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
  int maxCount(int m, int n, vector<vector<int>> &ops) {

    int overlap[] = {m, n};

    for (const auto &op : ops) {

      overlap[0] = min(overlap[0], op[0]);
      overlap[1] = min(overlap[1], op[1]);
    }

    return overlap[0] * overlap[1];
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
