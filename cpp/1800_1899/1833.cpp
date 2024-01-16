#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum = 0;
        int ret = 0;
        for(; sum < coins && ret < costs.size(); ++ret){
            sum+= costs[ret];
        }
        if(sum > coins){
            return ret - 1;
        }
        return ret;
    }
};
