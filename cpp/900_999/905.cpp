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
  vector<int> sortArrayByParity(vector<int> &nums) {

    int end = nums.size();

    for (int i = 0; i < end;) {

      if (nums[i] % 2 == 0) {
        // to head

        ++i;
        continue;
      }

      swap(nums[i], nums[end - 1]);
      --end;
    }
    return nums;
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
