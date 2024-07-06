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

bool op(int lhs, int rhs) { return lhs > rhs; }
// jj
class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) {
    most.swap(nums);
    sort(most.begin(), most.end(), op);
    most.resize(min((int)most.size(), k));
    most.reserve(k);
    k_ = k;
  }
  int k_;

  int add(int val) {
    const bool full = most.size() == k_;
    auto pos = lower_bound(most.begin(), most.end(), val, op);

    if (full && pos == most.end()) {
      return most.back();
    }

    most.insert(pos, val);
    most.resize(min((int)most.size(), k_));
    most.reserve(k_);
    return most.back();
  }

private:
  std::vector<int> most;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

#ifdef LEETCODE
int main() {
  {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest k(3, nums);
    assert(k.add(3) == 4);
    assert(k.add(5) == 5);
    assert(k.add(10) == 5);
    assert(k.add(9) == 8);
    assert(k.add(4) == 8);

    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
