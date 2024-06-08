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
  bool satisfiesConditions(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.front().size() - 1; ++i) {
      if (grid.front()[i] == grid.front()[i + 1]) {
        return false;
      }
    }

    for (int j = 1; j < grid.size(); ++j) {
      for (int i = 0; i < grid[j].size(); ++i) {
        if (grid[j][i] != grid[j - 1][i]) {
          return false;
        }
      }
    }
    return true;
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
