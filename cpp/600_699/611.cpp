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
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int side0 = nums[i];
      for (int j = i + 1; j < nums.size(); ++j) {
        int side1 = nums[j];

        int side2_max_possible = side0 + side1 - 1;
        const auto pos =
            lower_bound(nums.begin() + j + 1, nums.end(), side2_max_possible) -
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
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
