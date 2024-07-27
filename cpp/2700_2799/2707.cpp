#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {

    vector<int> cache(s.size(), -1);

    return rec(s, 0, dictionary, cache);
  }

  int rec(const string &s, const int pos, const vector<string> &dict,
          vector<int> &cache) {
    if (pos == s.size()) {
      return 0;
    }

    if (cache[pos] != -1) {
      return cache[pos];
    }

    int best = s.size() - pos;
    for (const auto &str : dict) {

      auto find_pos = s.find(str, pos);
      if (find_pos == string::npos) {
        continue;
      }

      int gap = find_pos - pos;

      int sub = rec(s, find_pos + str.size(), dict, cache);

      int this_res = gap + sub;
      best = min(best, this_res);
    }

    cache[pos] = best;

    return best;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    string str = "leetscode";
    vector<string> dictionary = {"leet", "code", "leetcode"};
    assert(s.minExtraChar(str, dictionary) == 1);
  }
}
#endif
