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
  int findWinningPlayer(vector<int> &skills, int k) {
    int max_count = 0;
    int current_player = 0;
    int current_skill = skills[current_player];
    for (int idx = 1; idx < skills.size() && max_count < k; ++idx) {
      if (skills[idx] < current_skill) {
        ++max_count;
        continue;
      }

      current_player = idx;
      current_skill = skills[current_player];
      max_count = 1;
    }

    return current_player;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
