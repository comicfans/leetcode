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
  int maxTotalReward(vector<int> &rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    rewardValues.resize(unique(rewardValues.begin(), rewardValues.end()) -
                        rewardValues.begin());

    vector<int> possibleSum = {0, rewardValues[0]};

    for (int i = 1; i < rewardValues.size(); ++i) {
      vector<int> addThis;
      for (auto v : possibleSum) {
        if (v >= rewardValues[i]) {
          break;
        }
        addThis.push_back(v + rewardValues[i]);
      }

      vector<int> merged;

      for (int lhs = 0, rhs = 0;
           lhs != possibleSum.size() || rhs != addThis.size();) {
        if (lhs == possibleSum.size()) {
          // copy rhs
          copy(addThis.begin() + rhs, addThis.end(), back_inserter(merged));
          break;
        }

        if (rhs == addThis.size()) {
          copy(rewardValues.begin() + lhs, rewardValues.end(),
               back_inserter(merged));
          break;
        }

        if (possibleSum[lhs] == addThis[rhs]) {
          merged.push_back(possibleSum[lhs]);
          ++lhs;
          ++rhs;
          continue;
        }
        if (possibleSum[lhs] < addThis[rhs]) {
          merged.push_back(possibleSum[lhs]);
          ++lhs;
          continue;
        }

        merged.push_back(addThis[rhs]);
        ++rhs;
      }

      swap(merged, possibleSum);
    }

    return possibleSum.back();
  }
  int maxTotalReward2(vector<int> &rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    rewardValues.resize(unique(rewardValues.begin(), rewardValues.end()) -
                        rewardValues.begin());
    int current = 0;
    return rec(rewardValues, 0, current);
  }

  int rec(const vector<int> &rewardValues, const int index, const int current) {
    if (index == rewardValues.size()) {
      return 0;
    }

    const int upper =
        upper_bound(rewardValues.begin() + index, rewardValues.end(), current) -
        rewardValues.begin();

    int subBest = 0;
    for (int i = upper; i < rewardValues.size(); ++i) {
      const int subRes =
          rec(rewardValues, i + 1, current + rewardValues[i]) + rewardValues[i];
      subBest = max(subBest, subRes);
    }
    return subBest;
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI input = {2, 15, 13, 3};
    auto res = s.maxTotalReward(input);
    assert(res == 28);
  }
  {
    VI input = {4, 13, 16};
    auto res = s.maxTotalReward(input);
    assert(res == 29);
  }
  {
    VI input = {3, 14, 12};
    auto res = s.maxTotalReward(input);
    assert(res == 26);
  }
  {
    VI input = {1, 1, 3, 3};
    auto res = s.maxTotalReward(input);
    assert(res == 4);
    // VVI = {};
  }
  {
    VI input = {1, 6, 4, 3, 2};

    auto res = s.maxTotalReward(input);
    assert(res == 11);
  }
}
#endif
