#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int getLargestOutlier(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);

    for (int idx = nums.size() - 1; idx >= 0;) {

      int left = sum - nums[idx];
      if (left % 2 == 0) {
        int exist = left / 2;
        // search exist
        if (binary_search(nums.begin(), nums.begin() + idx, exist) ||
            binary_search(nums.begin() + idx + 1, nums.end(), exist)) {
          return nums[idx];
        }
      }
      // find next different value
      auto next = upper_bound(nums.begin(), nums.begin() + idx, nums[idx] - 1);
      --next;
      idx = next - nums.begin();
    }
    assert(false);
  }
};

#ifdef LEETCODE

#include "../parse.h"
int main() {
  Solution s;
  {
    VI input = {2, 3, 5, 10};
    assert(s.getLargestOutlier(input) == 10);
  }
  {
    VI input = {-2, -1, -3, -6, 4};
    assert(s.getLargestOutlier(input) == 4);
  }
  {

    VI input = {1, 1, 1, 1, 1, 5, 5};
    assert(s.getLargestOutlier(input) == 5);
  }
  {

    VI input = {-108, -108, -507};
    assert(s.getLargestOutlier(input) == 5);
  }
}
#endif
