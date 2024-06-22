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
  string findLatestTime(string s) {

    for (int i = 0; i < s.size(); ++i) {
      if (i == 2 || s[i] != '?') {
        continue;
      }
      if (i == 0) {
        if (s[1] == '1' || s[1] == '0' || s[1] == '?') {
          s[i] = '1';
        } else {
          s[i] = '0';
        }
        continue;
      }

      if (i == 1) {
        if (s[0] == '0') {
          s[1] = '9';
        } else {
          s[1] = '1';
        }
        continue;
      }

      if (i == 3) {
        s[i] = '5';
        continue;
      }
      s[i] = '9';
    }

    return s;
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
