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
  int valueAfterKSeconds(int n, int k) {

    vector<long long> all(n, 1);
    for (int i = 1; i < k; ++i) {
      for (int j = 1; j < n; ++j) {
        all[j] = (all[j] + all[j - 1]) % (1000000007);
      }
    }
    return all.back();
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    int res = s.valueAfterKSeconds(4, 5);
    assert(res == 56);
  }
  {
    int res = s.valueAfterKSeconds(5, 3);
    assert(res == 35);
    // VI = {};
    // VVI = {};
  }
}
#endif
