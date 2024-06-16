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
  long long countCompleteDayPairs(vector<int> &hours) {

    map<int, int> mod;
    for (auto v : hours) {
      mod[v % 24]++;
    }

    long long res = 0;
    if (mod[0] > 0) {
      res += (long long)mod[0] * (long long)(mod[0] - 1) / 2;
    }

    for (int mm = 1; mm < 12; ++mm) {
      long long this_one = (long long)mod[mm] * (long long)mod[24 - mm];
      res += this_one;
    }

    if (mod[12] > 0) {
    }

    return res;
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
