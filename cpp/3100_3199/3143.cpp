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
  int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
    vector<pair<int, char>> ordered;

    for (int i = 0; i < points.size(); ++i) {
      int minHalf = max(abs(points[i][0]), abs(points[i][1]));

      ordered.push_back({minHalf, s[i]});
    }
    sort(ordered.begin(), ordered.end());

    set<char> reached;
    for (int i = 0; i < ordered.size();) {
      auto end = upper_bound(ordered.begin() + i, ordered.end(),
                             make_pair(ordered[i].first, 'z')) -
                 ordered.begin();
      set<char> stage;

      for (int j = i; j < end; ++j) {
        char thisChar = ordered[j].second;
        if (reached.count(thisChar) || stage.count(thisChar)) {
          return reached.size();
        }
        stage.insert(thisChar);
      }

      copy(stage.begin(), stage.end(), inserter(reached, reached.end()));
      i = end;
    }
    return reached.size();
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {

    VVI points = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
    string names = "abdca";
    auto res = s.maxPointsInsideSquare(points, names);
    assert(res == 2);
  }
  {
    VVI points = {{10, -12}, {-5, -4}, {-7, 15}, {9, 16}};
    string names = "dada";
    auto res = s.maxPointsInsideSquare(points, names);
    assert(res == 2);
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
