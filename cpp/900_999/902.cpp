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
  int atMostNGivenDigitSet(vector<string> &digits, int n) {

    vector<int> digits_int(digits.size());
    transform(digits.begin(), digits.end(), digits_int.begin(),
              [](const auto &s) { return s[0] - '0'; });

    int width = 0;
    int test_width = n;
    while (test_width > 0) {
      test_width /= 10;
      width++;
    }
    if (n == 0) {
      width = 1;
    }

    int res = 0;
    bool has_zero = (digits.front() == "0");
    for (int try_width = 1; try_width < width; ++try_width) {

      if (try_width == 1) {
        res += digits.size();
        continue;
      }

      int this_res = 1;
      for (int i = 0; i < try_width; ++i) {

        int mul = digits.size();
        if (i == 0 && has_zero) {
          --mul;
        }
        this_res *= mul;
      }
      res += this_res;
    }

    int same_width_res = rec(n, width, digits_int, 0);
    res += same_width_res;
    return res;
  }

  int rec(const int left, const int width, const vector<int> &digits,
          const int pos) {

    if (pos == width) {
      return 1;
    }

    int top_digit = left / pow(10, width - 1 - pos);

    int idx =
        lower_bound(digits.begin(), digits.end(), top_digit) - digits.begin();

    if (idx == 0 && digits[idx] > top_digit) {
      return 0;
    }

    int res = 0;
    for (int i = 0; i < idx; ++i) {
      if (pos == 0 && digits[i] == 0) {
        continue;
      }

      const int left_width = width - pos - 1;

      int this_res = pow(digits.size(), left_width);
      res += this_res;
    }

    if (idx != digits.size() && digits[idx] == top_digit) {
      int sub_left = left - top_digit * pow(10, width - 1 - pos);
      int sub_res = rec(sub_left, width, digits, pos + 1);
      res += sub_res;
    }

    return res;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    vector<string> digits = {"5", "7", "8"};
    int n = 59;
    assert(s.atMostNGivenDigitSet(digits, n) == 6);
  }
  {
    vector<string> digits = {"7"};
    int n = 8;
    assert(s.atMostNGivenDigitSet(digits, n) == 1);
  }
  {
    vector<string> digits = {"3", "4", "8"};
    int n = 4;
    assert(s.atMostNGivenDigitSet(digits, n) == 2);
  }
  {
    vector<string> digits = {"1", "3", "5", "7"};
    int n = 100;
    assert(s.atMostNGivenDigitSet(digits, n) == 20);
    // VI = {};
    // VVI = {};
  }
  {
    vector<string> digits = {"1", "4", "9"};
    int n = 1000000000;
    assert(s.atMostNGivenDigitSet(digits, n) == 29523);
    // VI = {};
    // VVI = {};
  }
}
#endif
