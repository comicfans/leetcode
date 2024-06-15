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

    if (sum != 0) {
      auto pos = cache.find({sum, begin, end});
      if (pos != cache.end()) {
        return pos->second;
      }
    }
    int used_sum = sum;

    int best = 0;
    int head_res = 0;
    int head_sum = nums[begin] + nums[begin + 1];
    if (head_sum == sum || sum == 0) {
      head_res = 1 + rec(nums, begin + 2, end, head_sum, cache);
      if (head_res > best) {
        best = head_res;
        used_sum = head_sum;
      }
    }
    int head_tail_res = 0;
    int head_tail_sum = nums[begin] + nums[end - 1];
    if (head_tail_sum == sum || sum == 0) {
      head_tail_res = 1 + rec(nums, begin + 1, end - 1, head_tail_sum, cache);
      if (head_tail_res > best) {
        best = head_tail_res;
        used_sum = head_tail_sum;
      }
    }

    int tail_res = 0;
    int tail_sum = nums[end - 1] + nums[end - 2];
    if (tail_sum == sum || sum == 0) {
      tail_res = 1 + rec(nums, begin, end - 2, tail_sum, cache);
      if (tail_res > best) {
        best = tail_res;
        used_sum = tail_sum;
      }
    }

    cache[{used_sum, begin, end}] = best;
    return best;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI input = {2, 2, 1, 2, 1};
    auto res = s.maxOperations(input);
    assert(res == 2);
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
