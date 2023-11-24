#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {

        int64_t res = (int64_t)dividend  / (int64_t)divisor;

        int cast = min<int64_t>(max<int64_t>(res, numeric_limits<int>::min()), numeric_limits<int>::max());
        return cast;
    }
};
