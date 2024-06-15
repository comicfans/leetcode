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
  long long numberOfRightTriangles(vector<vector<int>> &grid) {

    vector<int> y_number(grid.size(), 0);
    vector<int> x_number(grid.front().size(), 0);

    for (int y = 0; y < grid.size(); ++y) {
      for (int x = 0; x < grid[y].size(); ++x) {

        x_number[x] += grid[y][x];
        y_number[y] += grid[y][x];
      }
    }

    long long ret = 0;
    for (int yc = 0; yc < grid.size(); ++yc) {
      const int yy = y_number[yc];
      for (int xc = 0; xc < grid[yc].size(); ++xc) {
        const auto xx = x_number[xc];
        if (grid[yc][xc] == 0) {
          continue;
        }
        auto mul = (long long)max(yy - 1, 0) * (long long)max(xx - 1, 0);
        ret += mul;
      }
    }
    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VVI input = {{0, 1, 0}, {0, 1, 1}, {0, 1, 0}};
    auto res = s.numberOfRightTriangles(input);
    assert(res == 2);
  }
  {

    VVI input = {{1, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}};
    auto res = s.numberOfRightTriangles(input);
    assert(res == 0);

    // VI = {};
    // VVI = {};
  }
}
#endif
