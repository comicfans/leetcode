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

    if (list2.size() < list1.size()) {
      swap(list1, list2);
    }

    unordered_map<string, int> idx1;

    for (auto i = 0; i < list1.size(); ++i) {
      idx1[list1[i]] = i;
    }

    unordered_map<string, int> least;
    int least_sum = INT_MAX;
    for (auto idx2 = 0; idx2 < list2.size(); ++idx2) {
      auto pos1 = idx1.find(list2[idx2]);
      if (pos1 == idx1.end()) {
        continue;
      }
      int this_sum = idx2 + pos1->second;
      least[list2[idx2]] = this_sum;
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
