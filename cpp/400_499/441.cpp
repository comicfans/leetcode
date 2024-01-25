#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {

        return (sqrt(1 + (double)n* 8)-1)/2;
    }
};
