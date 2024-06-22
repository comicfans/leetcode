#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
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
  int sumOfEncryptedInt(vector<int> &nums) {
    for (auto &v : nums) {
      int d = 0;
      int count = 0;
      while (v > 0) {
        d = max(d, v % 10);
        ++count;
        v /= 10;
      }
      for (int i = 0; i < count; ++i) {
        v += d;
        d *= 10;
      }
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI nums = {10, 21, 31};
    auto res = s.sumOfEncryptedInt(nums);
    assert(res == 66);
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
