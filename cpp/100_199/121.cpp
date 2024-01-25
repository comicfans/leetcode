#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty()){
            return 0;
        }

        int currentMin = prices[0];
        int ret = 0;

        for(int i = 1;i<prices.size();++i){
           

            ret = max(ret, prices[i]-prices[i-1]);
         
            ret = max(ret,prices[i]-currentMin);

            currentMin = min(currentMin, prices[i]);
        }
        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<int> prices = {1,2,4};
        auto res = s.maxProfit(prices);
        assert(res == 3);
    }
    {
        vector<int> prices = {2,1,2,0,1};
        auto res = s.maxProfit(prices);
        assert(res == 1);
    }
    {
        vector<int> prices = {7,1,5,3,6,4};

        auto res = s.maxProfit(prices);
        assert(res == 5);
    }
    {
        vector<int> prices = {2,2,5};

        auto res = s.maxProfit(prices);
        assert(res == 3);
    }
    
    
}

