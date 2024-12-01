#include <cassert>
class Solution {
public:
  int smallestNumber(int n) {

    int bit = 0;
    while (n > 0) {
      n = n / 2;
      ++bit;
    }

    int res = (1 << bit) - 1;
    return res;
  }
};

int main() {
  Solution s;
  assert(s.smallestNumber(5) == 7);
}
