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

struct Serial {

  set<int> types;
  vector<pair<int, int>> tail_type_count;
};

class Solution {
public:
  int totalFruit(vector<int> &fruits) {

    int best = 1;
    int last_count = 1;
    int prev_count = 0;
    int prev_type = -1;
    int current_count = 1;

    for (int i = 1; i < fruits.size(); ++i) {

      if (fruits[i] == fruits[i - 1]) {
        ++last_count;
        ++current_count;
        best = max(best, current_count);
        continue;
      }

      if (fruits[i] == prev_type) {
        current_count++;
        best = max(best, current_count);
        prev_count = last_count;
        last_count = 1;
        prev_type = fruits[i - 1];
        continue;
      }

      // new one
      prev_type = fruits[i - 1];
      prev_count = last_count;
      last_count = 1;
      current_count = prev_count + last_count;
      best = max(best, current_count);
    }

    return best;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI input = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    assert(s.totalFruit(input) == 5);
  }
  {
    VI input = {1, 2, 1};
    assert(s.totalFruit(input) == 3);
  }
  {
    VI input = {0, 1, 2, 2};
    assert(s.totalFruit(input) == 3);
  }
  {

    VI input = {1, 2, 3, 2, 2};
    assert(s.totalFruit(input) == 4);
  }
}
#endif
