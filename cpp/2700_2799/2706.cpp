#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int backup = money;
        sort(prices.begin(),prices.end());
        money -= prices[0];
        money -= prices[1];
        return money>=0?money:backup;
    }
};
