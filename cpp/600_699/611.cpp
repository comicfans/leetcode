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
  int triangleNumber(vector<int> &nums) {
    if (nums.size() < 3) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      int side0 = nums[i];
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        int side1 = nums[j];

        int side2_max_possible = side0 + side1 - 1;
        const auto pos =
            upper_bound(nums.begin() + j + 1, nums.end(), side2_max_possible) -
            nums.begin();

        int this_count = pos - j - 1;
        ret += this_count;
      }
    }
    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI nums = {2, 2, 3, 4};
    assert(s.triangleNumber(nums) == 3);
  }
  {
    VI nums = {4, 2, 3, 4};
    assert(s.triangleNumber(nums) == 4);
    // VI = {};
    // VVI = {};
  }
}
#endif
