#include <algorithm>
#include <bit>
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
  bool canSortArray(vector<int> &nums) {

    int current_bits = std::popcount((uint16_t)nums.front());
    int current_max = nums.front();
    int prev_max = -1;

    for (int i = 1; i < nums.size(); ++i) {
      int this_bit = std::popcount((uint16_t)nums[i]);
      if (this_bit == current_bits) {
        if (nums[i] < prev_max) {
          return false;
        }
        current_max = max(current_max, nums[i]);
        continue;
      }
      prev_max = current_max;
      // can't swap
      current_max = nums[i];
      if (current_max < prev_max) {
        return false;
      }
      current_bits = this_bit;
    }
    return true;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI nums = {8, 4, 2, 30, 15};
    assert(s.canSortArray(nums));
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
