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
  int minOperations(vector<int> &nums, int k) {

    multiset<int64_t> sorted;

    for (auto v : nums) {
      if (v < k) {
        sorted.insert(v);
      }
    }
    int step = 0;
    while (*sorted.begin() < k && sorted.size() > 0) {

      if (sorted.size() == 1) {
        ++step;
        break;
      }

      auto pos0 = sorted.begin();
      int64_t v0 = *pos0;
      sorted.erase(sorted.begin());
      int64_t v1 = *sorted.begin();
      sorted.erase(sorted.begin());
      auto added = v0 * 2 + v1;
      ++step;
      if (added < k) {
        sorted.insert(added);
      }
    }

    return step;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI nums = {2, 11, 10, 1, 3};
    int k = 10;
    assert(s.minOperations(nums, k) == 2);
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
