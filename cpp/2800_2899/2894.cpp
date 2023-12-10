#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int differenceOfSums(int n, int m) {

        int all = (1+n) * n / 2;

        int group = n / m;
        int div = (1+group) * group / 2 * m;

        return all - div - div;

    }
};
