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
  int maxOperations(vector<int> &nums) {
    map<tuple<int, int, int>, int> cache;
    return rec(nums, 0, nums.size(), 0, cache);
  }

  int rec(const vector<int> &nums, const int begin, const int end,
          const int sum, map<tuple<int, int, int>, int> &cache) {

    if (end - begin < 2) {
      return 0;
    }

    const auto head_sum = nums[begin] + nums[begin + 1];
    const auto head_tail_sum = nums[begin] + nums[end - 1];
    const auto tail_sum = nums[end - 1] + nums[end - 2];

    if (sum != 0) {

      auto pos = cache.find({sum, begin, end});
      if (pos != cache.end()) {
        return pos->second;
      }

      int best = 0;
      if (head_sum == sum) {
        best = 1 + rec(nums, begin + 2, end, sum, cache);
      }

      if (head_tail_sum == sum) {
        int head_tail_res = 1 + rec(nums, begin + 1, end - 1, sum, cache);
        best = max(best, head_tail_res);
      }

      if (tail_sum == sum && tail_sum != head_sum) {
        int tail_res = 1 + rec(nums, begin, end - 2, sum, cache);
        best = max(best, tail_res);
      }

      cache[{sum, begin, end}] = best;
      return best;
    }

    int best = 1 + rec(nums, begin + 2, end, head_sum, cache);

    int head_tail_res = 1 + rec(nums, begin + 1, end - 1, head_tail_sum, cache);
    best = max(best, head_tail_res);

    if (tail_sum != head_sum) {
      int tail_res = 1 + rec(nums, begin, end - 2, tail_sum, cache);
      best = max(best, tail_res);
    }
    return best;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {

    VI input = {3, 3, 7, 3, 2, 4, 2, 3};
    auto res = s.maxOperations(input);
    assert(res == 2);
  }
  {
    VI input = {2, 2, 1, 2, 1};
    auto res = s.maxOperations(input);
    assert(res == 2);
  }
  {

    VI input = {1, 1, 2, 3, 2, 2, 1, 3, 3};
    auto res = s.maxOperations(input);
    assert(res == 4);
    // VI = {};
    // VVI = {};
  }
}
#endif
