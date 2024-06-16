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
        if (q[2] - q[1] <= 1) {
          ret.push_back(0);
          continue;
        }

        int temp = cum_count[q[2]] - cum_count[q[1] + 1];

        ret.push_back(temp);
        continue;
      }
      // change value
      auto idx = q[1];
      auto v = q[2];

      const int center_idx = min(idx, 2);
      auto gen = [&nums, idx, center_idx](auto center) {
        const int after_number = min((int)nums.size() - 1 - idx, 2);
        vector<int> temp_old(center_idx + 1 + after_number);

        copy(nums.begin() + idx - center_idx, nums.begin() + idx,
             temp_old.begin());
        temp_old[center_idx] = center;
        copy(nums.begin() + idx + 1, nums.begin() + idx + 1 + after_number,
             temp_old.begin() + center_idx + 1);

        return temp_old;
      };

      auto temp_old = gen(nums[idx]);
      auto cum_old = cum(temp_old);
      auto temp_new = gen(v);
      auto cum_new = cum(temp_new);

      int cum_change = 0;
      for (int delta = -1; delta <= 2; ++delta) {
        if (idx + delta < 0 || idx + delta > nums.size() - 1) {
          continue;
        }
        cum_change = cum_new[center_idx + delta] - cum_old[center_idx + delta];
        cum_count[idx + delta] += cum_change;
      }
      if (cum_change == 0) {
        nums[idx] = v;
        continue;
      }
      for (int i = idx + 3; i < nums.size(); ++i) {
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
    VI input = {4, 9, 4, 10, 7};
    VVI queries = {{2, 3, 2}, {2, 1, 3}, {1, 2, 3}};
    auto res = s.countOfPeaks(input, queries);
  }
  {
    VI input = {8, 7, 10};
    VVI queries = {{1, 1, 1}, {2, 2, 4}, {1, 0, 1}, {2, 1, 9}, {1, 0, 2}};
    auto res = s.countOfPeaks(input, queries);
    VI expect = {0, 0, 1};
    assert(res == expect);
  }
  {
    VI input = {5, 6, 4, 5};
    VVI queries = {{2, 3, 9}, {1, 0, 2}, {1, 3, 3}};

    auto res = s.countOfPeaks(input, queries);
  }

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
