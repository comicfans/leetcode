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
  int findLHS(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int best = 0;
    int prev_value = -2;
    int prev_count = 0;
    for (int i = 0; i < nums.size();) {

      int value = nums[i];
      auto end =
          upper_bound(nums.begin() + i + 1, nums.end(), value) - nums.begin();
      int this_count = end - i;

      if (value == prev_value + 1) {
        best = max(best, prev_count + this_count);
      }
      prev_value = value;
      prev_count = this_count;
      i = end;
    }
    return best;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
