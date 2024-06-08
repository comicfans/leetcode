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
  vector<int> queryResults(int limit, vector<vector<int>> &queries) {

    unordered_map<int, int> ball_color;

    vector<int> ret(queries.size());
    unordered_map<int, int> color_count;
    int count = 0;
    for (int i = 0; i < queries.size(); ++i) {
      const int ball = queries[i][0];
      const int color = queries[i][1];

      const auto prev_color = ball_color[ball];

      if (prev_color == color) {
        ret[i] = ret[i - 1];
        continue;
      }

      if (prev_color != 0) {
        auto pos = color_count.find(prev_color);
        --pos->second;
        if (pos->second == 0) {
          --count;
        }
      }

      auto &new_color_count = color_count[color];
      if (new_color_count == 0) {
        ++count;
      }
      new_color_count++;
      ball_color[ball] = color;
      ret[i] = count;
    }

    return ret;
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
