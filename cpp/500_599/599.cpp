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
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {

    unordered_map<string, int> idx1, idx2;
    for (auto i = 0; i < list1.size(); ++i) {
      idx1[list1[i]] = i;
    }
    for (auto i = 0; i < list2.size(); ++i) {
      idx2[list2[i]] = i;
    }

    unordered_map<string, int> least;
    int least_sum = INT_MAX;
    for (const auto &[str, idx] : idx1) {
      auto pos2 = idx2.find(str);
      if (pos2 == idx2.end()) {
        continue;
      }
      int this_sum = idx + pos2->second;
      least[str] = this_sum;
      least_sum = min(least_sum, this_sum);
    }
    vector<string> ret;
    for (const auto &[str, sum] : least) {
      if (sum == least_sum) {
        ret.push_back(str);
      }
    }

    return ret;
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {
    vector<string> l1 = {"happy", "sad", "good"};
    vector<string> l2 = {"sad", "happy", "good"};
    auto res = s.findRestaurant(l1, l2);
    // VI = {};
    // VVI = {};
  }
  {
    vector<string> l1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> l2 = {"KFC", "Shogun", "Burger King"};
    auto res = s.findRestaurant(l1, l2);
    // VI = {};
    // VVI = {};
  }
}
#endif
