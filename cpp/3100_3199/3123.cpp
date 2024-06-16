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
  vector<bool> findAnswer(int n, vector<vector<int>> &edges) {
    vector<int> from_begin(n, INT_MAX);
    vector<int> from_end(n, INT_MAX);

    set<int> walked;

    rec_walk(walked, 0, edges, from_begin, n - 1, 0);

    if (from_begin.back() == INT_MAX) {
      return vector<bool>(edges.size(), false);
    }

    rec_walk(walked, n - 1, edges, from_end, 0, 0);
    vector<bool> ret;
    for (auto &edge : edges) {
      if (from_begin[edge[0]] != INT_MAX && from_end[edge[1]] != INT_MAX) {
        int dis1 = from_begin[edge[0]] + from_end[edge[1]];
        if (dis1 + edge[2] == from_begin.back()) {
          ret.push_back(true);
          continue;
        }
      }

      if (from_begin[edge[1]] == INT_MAX || from_end[edge[0]] == INT_MAX) {
        ret.push_back(false);
        continue;
      }

      int dis2 = from_begin[edge[1]] + from_end[edge[0]];
      ret.push_back(dis2 + edge[2] == from_begin.back());
    }

    return ret;
  }

  void rec_walk(set<int> &walked, const int last,
                const vector<vector<int>> &edges, vector<int> &result,
                const int target, const int distance) {

    if (distance >= result[last]) {
      return;
    }
    result[last] = distance;
    if (last == target) {
      return;
    }

    auto pos = walked.insert(last);
    for (const auto &edge : edges) {
      for (auto test_from : {0, 1}) {

        if (edge[test_from] != last) {
          continue;
        }

        int next = edge[1 - test_from];
        if (walked.count(next)) {
          continue;
        }
        rec_walk(walked, next, edges, result, target, distance + edge[2]);
      }
    }
    walked.erase(pos.first);
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    const int n = 3;
    VVI edges = {{2, 1, 6}};

    vector<bool> expect = {false};

    auto res = s.findAnswer(n, edges);
    assert(res == expect);
  }
  {
    const int n = 7;
    VVI edges = {{4, 5, 4}, {6, 5, 1}, {0, 4, 9},  {2, 5, 1}, {3, 5, 6},
                 {1, 3, 6}, {0, 2, 2}, {0, 5, 10}, {6, 2, 10}};

    vector<bool> expect = {false, true, false, true, false,
                           false, true, false, false};

    auto res = s.findAnswer(n, edges);
    assert(res == expect);
  }
  {
    const int n = 5;
    VVI edges = {{1, 0, 8}, {2, 1, 5}, {3, 2, 7}, {4, 3, 2}, {0, 2, 9}};
    vector<bool> expect = {false, false, true, true, true};
    auto res = s.findAnswer(n, edges);
    assert(res == expect);
  }
  {
    // VI = {};
    // VVI = {};
    const int n = 6;
    VVI edges = {{0, 1, 4}, {0, 2, 1}, {1, 3, 2}, {1, 4, 3},
                 {1, 5, 1}, {2, 3, 1}, {3, 5, 3}, {4, 5, 2}};

    vector<bool> expect = {true, true, true, false, true, true, true, false};
    auto res = s.findAnswer(n, edges);
    assert(res == expect);
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
