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
  int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int currentBest = INT_MIN;
    for (int tryIdx = 0; tryIdx < 3; ++tryIdx) {
      auto diff = nums1[tryIdx] - nums2[0];

      int joff = 0;
      int i2 = 1;
      for (; i2 < nums2.size() && joff <= 2 - tryIdx;) {
        const int thisDiff = nums1[tryIdx + joff + i2] - nums2[i2];
        if (thisDiff == diff) {
          ++i2;
          continue;
        }
        if (thisDiff > diff) {
          break;
        } else {
          ++joff;
        }
      }

      if (i2 == nums2.size()) {
        currentBest = max(currentBest, diff);
      }
    }

    return -currentBest;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI nums1 = {3, 3, 5, 5}, nums2 = {7, 7};
    auto res = s.minimumAddedInteger(nums1, nums2);
    assert(res == 2);
    // VVI = {};
  }
  {
    VI nums1 = {4, 20, 16, 12, 8}, nums2 = {14, 18, 10};
    auto res = s.minimumAddedInteger(nums1, nums2);
    assert(res == -2);
    // VVI = {};
  }
}
#endif
