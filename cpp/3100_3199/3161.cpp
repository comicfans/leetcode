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

struct MaxSegments {

  map<int, set<int>> segments = {{0, {0}}};
  vector<int> ordered_pos = {0};
  void insert(const int pos) {
    auto lower = lower_bound(ordered_pos.begin(), ordered_pos.end(), pos) -
                 ordered_pos.begin();

    const bool last = (lower == ordered_pos.size());

    assert(lower != 0);
    int length = pos - ordered_pos[lower - 1];
    segments[length].insert(pos);

    ordered_pos.insert(ordered_pos.begin() + lower, pos);
    if (last) {
      return;
    }

    const auto right = ordered_pos[lower + 1];
    const int old_length = right - ordered_pos[lower - 1];
    const int new_length = old_length - length;
    auto seg_pos = segments.find(old_length);
    assert(seg_pos != segments.end());
    auto pos_it = seg_pos->second.find(right);
    assert(pos_it != seg_pos->second.end());
    seg_pos->second.erase(pos_it);
    if (seg_pos->second.empty()) {
      segments.erase(seg_pos);
    }
    segments[new_length].insert(right);
  }
  bool find(const int right, const int size) {
    // from 0 to right

    auto possible = segments.lower_bound(size);
    while (possible != segments.end()) {
      const auto &rights = possible->second;
      const int firstPos = *rights.begin();
      if (firstPos <= right) {
        return true;
      }

      if (firstPos - possible->first + size <= right) {
        return true;
      }

      ++possible;
    }

    const int after = right - ordered_pos.back();

    return after >= size;
  }
};

// jj
class Solution {
public:
  vector<bool> getResults(vector<vector<int>> &queries) {
    vector<bool> ret;

    MaxSegments segments;
    for (const auto &q : queries) {
      if (q[0] == 1) {

        segments.insert(q[1]);
        continue;
      }

      bool found = segments.find(q[1], q[2]);
      ret.push_back(found);
    }

    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VVI queries = {{1, 5}, {2, 2, 1}};

    auto res = s.getResults(queries);
    vector<bool> expect = {true};
    assert(expect == res);
  }
  {

    VVI queries = {{1, 7}, {2, 7, 6}, {1, 2}, {2, 7, 5}, {2, 7, 6}};
    auto res = s.getResults(queries);
    vector<bool> expect = {true, true, false};
    assert(expect == res);
  }
  {
    VVI queries = {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}};
    auto res = s.getResults(queries);
    vector<bool> expect = {false, true, true};
    assert(expect == res);
  }
}
#endif
