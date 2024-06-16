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
  long long maximumTotalDamage(vector<int> &power) {
    map<int, int> dem_count;

    for (auto d : power) {
      dem_count[d]++;
    }
    vector<long long> cache(dem_count.size(), -100);
    vector<pair<int, long long>> dem;
    dem.reserve(dem_count.size());
    for (auto [k, v] : dem_count) {
      dem.push_back({k, (long long)k * (long long)v});
    }

    return rec(dem, 0, -100, cache);
  }

  long long rec(const vector<pair<int, long long>> &dem, int pos, int prev,
                vector<long long> &cache) {
    if (pos == dem.size()) {
      return 0;
    }

    if (cache[pos] != -100) {
      return cache[pos];
    }
    // find next valid

    long long best = 0;
    int first_try = -100;
    for (int i = pos; i < dem.size(); ++i) {
      if (dem[i].first <= prev + 2) {
        continue;
      }
      if (first_try == -100) {
        first_try = dem[i].first;
      } else {
        if (dem[i].first > first_try + 2) {
          break;
        }
      }

      long long this_dem = dem[i].second;
      auto sub = rec(dem, i + 1, dem[i].first, cache);
      best = max(best, this_dem + sub);
    }

    cache[pos] = best;
    return best;
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {
    VI input(100000);
    for (int i = 0; i < 100000; ++i) {
      input[i] = rand() % 1000000000;
    }

    auto res = s.maximumTotalDamage(input);
    int a = 3;

    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
