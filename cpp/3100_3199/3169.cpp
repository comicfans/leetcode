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
  int countDays(int days, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end());
    if (meetings.empty()) {
      return days;
    }

    int start = meetings.front()[0];
    int end = meetings.front()[1];

    int meeting_days = 0;
    int pos = 1;

    for (; pos != meetings.size(); ++pos) {

      auto thisSegment = meetings[pos];

      if (thisSegment[0] > end) {
        int meet = end - start + 1;
        meeting_days += meet;
        start = thisSegment[0];
        end = thisSegment[1];
        continue;
      }

      end = max(thisSegment[1], end);
    }

    int meet = end - start + 1;
    meeting_days += meet;

    return days - meeting_days;
  }
};
// jj

#ifdef LEETCODE
int main() {
  Solution s;
  {
    VVI meetings = {{5, 7}, {1, 3}, {9, 10}};
    auto res = s.countDays(10, meetings);
    assert(res == 2);
  }
  {
    VVI meetings = {{1, 3}, {2, 4}};

    auto res = s.countDays(5, meetings);
    assert(res == 1);
  }
}
#endif
