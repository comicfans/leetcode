#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
int sign(int v) {
  if (v == 0) {
    return 0;
  }
  if (v > 0) {
    return 1;
  }

  return -1;
}

#ifdef LEETCODE
#include "../parse.h"
#endif

// jj
class Solution {
public:
  vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries) {

    auto cum = [](const vector<int> &nums) {
      vector<int> cum_count(nums.size(), 0);
      int total = 0;
      for (int i = 1; i < nums.size() - 1; ++i) {
        cum_count[i] = total;
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
          ++total;
        }
      }
      cum_count.back() = total;
      return cum_count;
    };

    auto cum_count = cum(nums);

    vector<int> ret;
    for (const auto &q : queries) {
      if (q[0] == 1) {

        int temp = cum_count[q[2]] - cum_count[q[1]];
        if (temp != 0 && q[0] != q[1] && q[1] != cum_count.size() - 1 &&
            cum_count[q[1]] != cum_count[q[1] + 1]) {
          --temp;
        }

        ret.push_back(temp);
        continue;
      }
      // change value
      auto idx = q[1];
      auto v = q[2];

      auto gen = [&nums, idx](int center) {
        vector<int> temp_old(5);
        temp_old[2] = center;
        temp_old[1] = idx > 0 ? nums[idx - 1] : temp_old[2];
        temp_old[0] = idx > 1 ? nums[idx - 2] : temp_old[1];
        temp_old[3] = idx < nums.size() - 1 ? nums[idx + 1] : temp_old[2];
        temp_old[4] = idx < nums.size() - 2 ? nums[idx + 2] : temp_old[2];
        return temp_old;
      };

      auto temp_old = gen(nums[idx]);
      auto cum_old = cum(temp_old);
      auto temp_new = gen(v);
      auto cum_new = cum(temp_new);

      int cum_change = 0;
      for (int delta = -1; delta <= 1; ++delta) {
        if (idx + delta < 0 || idx + delta > nums.size() - 1) {
          continue;
        }
        cum_change += (cum_new[1 + delta] - cum_old[1 + delta]);
        cum_count[idx + delta] += cum_change;
      }
      if (cum_change == 0) {
        continue;
      }
      for (int i = idx + 2; i < nums.size(); ++i) {
        cum_count[i] += cum_change;
      }
      nums[idx] = v;
      auto check = cum(nums);
      assert(check == cum_count);
    }

    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;

  {
    VI input = {8, 10, 10, 9, 10};
    VVI queries = {{2, 0, 1}, {2, 2, 7}, {1, 0, 2}};
    VI expect = {1};

    auto res = s.countOfPeaks(input, queries);
    assert(res == expect);
  }
  {
    VI input = {5, 4, 8, 6};
    VVI queries = {{1, 2, 2}, {1, 1, 2}, {2, 1, 6}};
    VI expect = {0, 0};

    auto res = s.countOfPeaks(input, queries);
    assert(res == expect);
  }
  {
    VI input = {4, 1, 4, 2, 1, 5};
    VVI queries = {{2, 2, 4}, {1, 0, 2}, {1, 0, 4}};
    VI expect = {0, 1};

    auto res = s.countOfPeaks(input, queries);
    assert(res == expect);
  }
  {
    VI input = {8, 5, 9, 3, 5};
    VVI queries = {{1, 2, 4}, {1, 0, 1}, {2, 2, 4}};
    VI expect = {0, 0};

    auto res = s.countOfPeaks(input, queries);
    assert(res == expect);
  }
  {
    VI input = {3, 1, 4, 2, 5};
    VVI queries = {{2, 3, 4}, {1, 0, 4}};

    VI expect = {0};
    auto res = s.countOfPeaks(input, queries);
    assert(res == expect);
    // VI = {};
    // VVI = {};
  }
  {
    VI input = {4, 1, 4, 2, 1, 5};
    VVI queries = {{2, 2, 4}, {1, 0, 2}, {1, 0, 4}};

    VI expect = {0, 1};
    auto res = s.countOfPeaks(input, queries);
    assert(res == expect);
    // VI = {};
    // VVI = {};
  }
}
#endif
