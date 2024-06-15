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
  int minimumOperations(vector<vector<int>> &grid) {

    vector<map<int, int>> status(grid.front().size());

    map<int, int> col_res = {{-1, 0}};

    for (int x = 0; x < grid.front().size(); ++x) {
      map<int, int> value_count;
      for (int y = 0; y < grid.size(); ++y) {
        value_count[grid[y][x]]++;
      }

      map<int, int> this_col_res = {};
      int prev_min_change = INT_MAX;
      for (auto [prev, prev_change] : col_res) {
        prev_min_change = min(prev_min_change, prev_change);
        for (auto [value, count] : value_count) {
          if (value == prev) {
            continue;
          }

          int this_change = prev_change + grid.size() - count;
          auto existing = this_col_res.find(value);
          if (existing != this_col_res.end()) {
            existing->second = min(existing->second, this_change);
          } else {
            this_col_res[value] = this_change;
          }
        }
      }

      this_col_res[-1] = prev_min_change + grid.size();
      swap(this_col_res, col_res);
    }
    int ret = INT_MAX;
    for (auto [value, change] : col_res) {
      ret = min(ret, change);
    }

    return ret;

    return ret;
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {
    VVI input = {{1, 1, 1}, {0, 0, 0}};
    auto res = s.minimumOperations(input);
    assert(res == 3);
  }

  {
    // VI = {};
    // VVI = {};
  }
}
#endif
