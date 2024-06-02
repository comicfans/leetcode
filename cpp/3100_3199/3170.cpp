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

class Solution {
public:
  string clearStars(string s) {
    string ret;

    int charCount[26] = {};
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '*') {
        ret.push_back(s[i]);
        charCount[s[i] - 'a']++;
        continue;
      }
      int delChar = -1;
      for (auto j = 0; j < 26; ++j) {
        if (charCount[j] > 0) {
          delChar = j;
          break;
        }
      }

      assert(delChar >= 0);
      charCount[delChar]--;
      char toDel = delChar + 'a';
      int retIdx = -1;
      for (int fi = ret.size() - 1; fi >= 0; --fi) {
        if (ret[fi] == toDel) {
          retIdx = fi;
          break;
        }
      }
      assert(retIdx != -1);
      ret.erase(ret.begin() + retIdx);
    }

    return ret;
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {
    string input = "dyk**dd*";

    auto res = s.clearStars(input);
    assert(res == "yd");
  }
  {
    string input = "x*tq*";
    auto res = s.clearStars(input);
    assert(res == "t");
  }
  {
    string input = "a*q";
    auto res = s.clearStars(input);
    assert(res == "q");
  }
  {
    string input = "aaba*";
    auto res = s.clearStars(input);
    assert(res == "aab");
  }
  {

    string input = "abc";
    auto res = s.clearStars(input);
    assert(res == "abc");
    // VI = {};
    // VVI = {};
  }
}
#endif
