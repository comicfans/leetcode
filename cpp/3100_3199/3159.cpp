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
  vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries,
                                   int x) {

    vector<int> ret(queries.size(), -1);

    vector<int> pos;
    int lastPos = -1;
    for (int i = 0; i < queries.size(); ++i) {
      int q = queries[i];
      while ((lastPos < (int)nums.size()) && (q > pos.size())) {
        ++lastPos;
        if (lastPos == nums.size()) {
          break;
        }
        if (nums[lastPos] == x) {
          pos.push_back(lastPos);
        }
      }

      if (q - 1 < pos.size()) {
        ret[i] = pos[q - 1];
      }
    }

    return ret;
  }
};

// jj

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI nums = {1, 3, 1, 7}, queries = {1, 3, 2, 4};
    int x = 1;
    auto res = s.occurrencesOfElement(nums, queries, x);

    VI expect = {0, -1, 2, -1};
    assert(res == expect);
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
