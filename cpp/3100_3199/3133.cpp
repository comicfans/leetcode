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
  long long minEnd(int n, int x) {
    // x

    // x + n1
    // x + nn
    // x   10.. 0.. 1 .. 0
    // next value
    //  lowest bit 0 pos => 1

    // -------repeat N times

    // zero in x can be used to increase
    int bitwidth = 0;

    int testN = n - 1;

    // turn n into binary represent
    // lower bit at left
    vector<bool> bits;
    while (testN > 0) {
      ++bitwidth;
      bits.push_back(testN % 2);
      testN /= 2;
    }

    vector<int> zeroPosInX;
    for (int i = 0; zeroPosInX.size() < bitwidth; ++i) {
      if (((long long)x & ((long long)(1) << i)) == 0) {
        zeroPosInX.push_back(i);
      }
    }
    // now fill them in
    assert(bits.size() == zeroPosInX.size());
    long long ret = x;
    for (int i = 0; i < zeroPosInX.size(); ++i) {
      ret = ret | ((long long)bits[i] << zeroPosInX[i]);
    }
    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    int n = 6715154, x = 7193485;

    auto res = s.minEnd(n, x);
  }
  {
    int n = 3, x = 4;
    auto res = s.minEnd(n, x);
    assert(res == 6);
  }
  {
    int n = 2, x = 7;
    auto res = s.minEnd(n, x);
    assert(res == 15);
  }
}
#endif
