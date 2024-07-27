#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// here
class Solution {
public:
  long long maxStrength(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int pos_begin = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();

    int positive_count = nums.size() - pos_begin;
    long long ret = 1;
    for (int i = pos_begin; i < nums.size(); ++i) {
      ret *= (long long)(nums[i]);
    }

    int neg_end =
        upper_bound(nums.begin(), nums.begin() + pos_begin, -1) - nums.begin();

    for (int i = 0; i < neg_end / 2 * 2; ++i) {
      ret *= (long long)(nums[i]);
    }

    bool has_zero =
        binary_search(nums.begin() + neg_end, nums.begin() + pos_begin, 0);

    if (positive_count + neg_end / 2 * 2 > 0) {
      return ret;
    }

    return has_zero ? 0 : nums[neg_end - 1];
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {}
  {}
}
#endif
