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
  long long maximumSubarraySum(vector<int> &nums, int k) {

    map<int, set<int>> value_pos;
    vector<long long> cumsum(nums.size());
    long long current_max = numeric_limits<long long>::min();

    long long prev = 0;
    for (int i = 0; i < nums.size(); ++i) {

      cumsum[i] = prev + nums[i];
      prev = cumsum[i];

      for (auto delta : {-k, k}) {
        auto another = (long long)nums[i] + delta;
        if (another < numeric_limits<int>::min() ||
            another > numeric_limits<int>::max()) {
          // out of range
          continue;
        }

        auto pos = value_pos.find(another);
        if (pos == value_pos.end()) {
          continue;
        }
        for (auto idx : pos->second) {
          long long sum = cumsum[i] - cumsum[idx] + nums[idx];
          current_max = max(current_max, sum);
        }
      }
      value_pos[nums[i]].insert(i);
    }

    return current_max == numeric_limits<long long>::min() ? 0 : current_max;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI nums = {999999980, 999999981, 999999982, 999999983, 999999984,
               999999985, 999999986, 999999987, 999999988, 999999989,
               999999990, 999999991, 999999992, 999999993, 999999994,
               999999995, 999999996, 999999997, 999999998, 999999999};
    int k = 18;
  }
  {
    VI nums = {1, 2, 3, 4, 5, 6};
    int k = 1;
    assert(s.maximumSubarraySum(nums, k) == 11);
    // VI = {};
    // VVI = {};
  }
  {
    VI nums = {1, 2, 3, 4, 5, 6};
    int k = 1;
    assert(s.maximumSubarraySum(nums, k) == 11);
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
