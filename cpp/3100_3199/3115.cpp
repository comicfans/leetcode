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
  struct Primes {
    int last_check = 32;
    vector<int> values = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    bool check_is(int v) {
      if (binary_search(values.begin(), values.end(), v)) {
        return true;
      }

      if (v <= last_check) {
        return false;
      }

      for (++last_check;; ++last_check) {
        if (last_check > v) {
          --last_check;
          break;
        }
        bool not_prime = false;
        for (auto p : values) {
          if (last_check % p == 0) {
            not_prime = true;
            break;
          }
        }

        if (not_prime) {
          continue;
        }

        values.push_back(last_check);
      }
      return values.back() == v;
    }
  };

  int maximumPrimeDifference(vector<int> &nums) {

    Primes prime;
    int begin = 0;
    for (begin = 0; begin < nums.size(); ++begin) {
      if (prime.check_is(nums[begin])) {
        break;
      }
    }

    int end = nums.size() - 1;
    for (; end >= 0; --end) {
      if (prime.check_is(nums[end])) {
        break;
      }
    }
    return end - begin;
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
