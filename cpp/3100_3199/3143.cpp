#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
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
  int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
    vector<pair<int, char>> ordered(points.size());

    for (int i = 0; i < points.size(); ++i) {
      int minHalf = max(abs(points[i][0]), abs(points[i][1]));

      ordered[i] = {minHalf, s[i]};
    }
    sort(ordered.begin(), ordered.end());

    bool reached[26] = {0};
    for (int i = 0; i < ordered.size();) {
      const auto end_idx = upper_bound(ordered.begin() + i, ordered.end(),
                                       make_pair(ordered[i].first, 'z')) -
                           ordered.begin();

      string stage_container;
      for (int j = i; j < end_idx; ++j) {
        char thisChar = ordered[j].second;
        int charIdx = thisChar - 'a';
        if (reached[charIdx]) {
          int walked = j - i;
          return std::accumulate(begin(reached), end(reached), 0) - walked;
        }
        reached[charIdx] = true;
      }

      i = end_idx;
    }
    return std::accumulate(begin(reached), end(reached), 0);
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {

    VVI points = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
    string names = "abdca";
    auto res = s.maxPointsInsideSquare(points, names);
    assert(res == 2);
  }
  {
    VVI points = {{10, -12}, {-5, -4}, {-7, 15}, {9, 16}};
    string names = "dada";
    auto res = s.maxPointsInsideSquare(points, names);
    assert(res == 2);
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
