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

    if (queries.empty()) {
      return {};
    }
    vector<int> pos;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == x) {
        pos.push_back(i);
      }
    }
    vector<int> ret(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      if (queries[i] - 1 >= pos.size()) {
        ret[i] = -1;
      } else {
        ret[i] = pos[queries[i] - 1];
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
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
