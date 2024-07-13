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
class StockSpanner {
public:
  StockSpanner() {}
  // 7, 2, 1, 2
  // 1, 1, 1, 3

  int next(int price) {

    int days = 1;
    while (!seq_res.empty() && seq_res.back().first <= price) {
      days += seq_res.back().second;
      seq_res.pop_back();
    }
    seq_res.push_back({price, days});
    return days;
  }
  vector<pair<int, int>> seq_res;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

#ifdef LEETCODE
int main() {
  {
    StockSpanner spanner;
    VI input = {100, 80, 60, 70, 60, 75, 85};
    VI expect = {1, 1, 1, 2, 1, 4, 6};
    for (int i = 0; i < input.size(); ++i) {
      auto res = spanner.next(input[i]);
      assert(res == expect[i]);
    }
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
