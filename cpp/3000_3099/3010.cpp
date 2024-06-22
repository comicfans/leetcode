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
  int minimumCost(vector<int> &nums) {
    auto mm = minmax(nums[1], nums[2]);
    int min2[] = {mm.first, mm.second};

    for (int i = 3; i < nums.size(); ++i) {
      if (nums[i] >= min2[1]) {
        continue;
      }
      if (nums[i] >= min2[0]) {
        min2[1] = nums[i];
        continue;
      }
      min2[1] = min2[0];
      min2[0] = nums[i];
    }

    return nums.front() + min2[0] + min2[1];
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
