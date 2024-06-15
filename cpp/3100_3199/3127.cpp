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
  bool canMakeSquare(vector<vector<char>> &grid) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int sum = 0;
        for (int x = 0; x < 2; ++x) {
          for (int y = 0; y < 2; ++y) {
            if (grid[y + i][x + j] == 'B') {
              ++sum;
            }
          }
        }
        if (sum != 2) {
          return true;
        }
      }
    }
    return false;
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
