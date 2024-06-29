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

struct Frac {
  int up;
  unsigned int down;

  Frac(string_view str) {

    int sign = 1;
    if (str[0] == '-') {
      sign = -1;

      str = str.substr(1);
    }

    auto div = str.find('/');
    assert(div != string::npos);
    up = stoi(string(str.substr(0, div))) * sign;
    down = stoi(string(str.substr(div + 1)));
  }

  const Frac &operator+=(const Frac &rhs) {

    auto common = lcm(down, rhs.down);

    up = up * (common / down) + rhs.up * (common / rhs.down);
    down = common;

    if (up != 0) {

      int gc = gcd(up, down);
      up /= gc;
      down /= gc;
    } else {
      down = 1;
    }

    return *this;
  }
};

class Solution {
public:
  string fractionAddition(string expression) {

    int start = 0;
    Frac init("0/1");
    while (true) {

      int pos = find_if(expression.begin() + start + 1, expression.end(),
                        [](auto c) { return c == '+' || c == '-'; }) -
                expression.begin();
      Frac thisOne(
          string_view(expression.begin() + start, expression.begin() + pos));
      init += thisOne;
      if (pos == expression.size()) {
        break;
      }
      start = pos;
    }

    string ret = to_string(init.up);
    ret.push_back('/');
    ret += to_string(init.down);
    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    string input = "-1/2+1/2";
    string expect = "0/1";
    auto res = s.fractionAddition(input);
    assert(res == expect);
    // VI = {};
    // VVI = {};
  }
  {
    auto expression = "-1/2+1/2+1/3";
    auto output = "1/3";
    auto res = s.fractionAddition(expression);
    assert(res == output);
    // VI = {};
    // VVI = {};
  }
  {
    auto expression = "1/3-1/2";
    auto Output = "-1/6";
    auto res = s.fractionAddition(expression);
    assert(res == Output);
  }
}
#endif
