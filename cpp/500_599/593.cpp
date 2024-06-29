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
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {

    vector<vector<int>> pv4{p1, p2, p3, p4};
    vector<double> dis_sq(p4.size());

    auto prev_idx = 0;
    bool used[4] = {false, false, false, false};
    used[prev_idx] = true;

    vector<int> order = {prev_idx};

    int prev_dis_sq = 0;
    for (int i = 0; i < 4; ++i) {

      int min_idx = 4;
      int min_sq = INT_MAX;
      for (int j = 0; j < 4; ++j) {
        if (j == prev_idx) {
          continue;
        }

        if (i != 3) {
          if (used[j]) {
            continue;
          }
        } else if (j != 0) {
          continue;
        }

        const int this_sq =
            (pv4[j][0] - pv4[prev_idx][0]) * (pv4[j][0] - pv4[prev_idx][0]) +
            (pv4[j][1] - pv4[prev_idx][1]) * (pv4[j][1] - pv4[prev_idx][1]);
        if (this_sq < min_sq) {
          min_sq = this_sq;
          min_idx = j;
        }
      }

      assert(min_idx != 4);

      if (min_sq == 0 || (prev_dis_sq != 0 && min_sq != prev_dis_sq)) {
        return false;
      }

      order.push_back(min_idx);

      used[min_idx] = true;
      prev_idx = min_idx;
      prev_dis_sq = min_sq;
      continue;
    }

    assert(std::all_of(used, used + 4, [](auto v) { return v; }));

    // check 90 degree
    int x1 = pv4[0][0] - pv4[order[1]][0];
    int y1 = pv4[0][1] - pv4[order[1]][1];

    int x2 = pv4[order[2]][0] - pv4[order[1]][0];
    int y2 = pv4[order[2]][1] - pv4[order[1]][1];

    int dot = x1 * y1 + x2 * y2;
    if (dot != 0) {
      return false;
    }

    return true;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VVI p4 = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};

    //                              |
    //                              p
    //                              |
    //                              |
    //                              |
    // -------------------p1---------+--------p0------------------
    //                              |
    //                              |
    //                              |
    //                              |

    assert(s.validSquare(p4[0], p4[1], p4[2], p4[3]));
  }
  {
    VVI p4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    //                              |
    //                              p
    //                              |
    //                              |
    //                              |
    // -------------------p1---------+--------p0------------------
    //                              |
    //                              |
    //                              |
    //                              |

    assert(s.validSquare(p4[0], p4[1], p4[2], p4[3]));
  }
  {
    //                              |
    //                              |
    //                              |
    //                              |
    //                              |
    //                              |
    //                              |   p2 (5,12)     p4 (18,12)
    //                              p
    //                              |
    //                              |
    //                              |
    // -----------------------------+--------p1------------------
    //                           p0 |        13
    //                              |
    //                              |

    VI p0 = {0, 0};
    VI p1 = {13, 0};
    VI p2 = {5, 12};
    VI p3 = {18, 12};
    assert(!s.validSquare(p0, p1, p2, p3));
  }
}
#endif
