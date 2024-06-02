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
  string compressedString(string word) {

    string ret;

    int count = 0;
    char prev = ' ';
    for (auto c : word) {
      if (c != prev || count == 9) {

        while (count > 0) {
          int num = min(9, count);
          ret.push_back(num + '0');
          ret.push_back(prev);
          count -= num;
        }
      }

      if (prev != c) {
        count = 1;
      } else {
        ++count;
      }

      prev = c;
    }
    while (count > 0) {
      int num = min(9, count);
      ret.push_back(num + '0');
      ret.push_back(prev);
      count -= num;
    }
    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    string input = "aaaaaaaaaaaaaabb";
    assert(s.compressedString(input) == "9a5a2b");
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
