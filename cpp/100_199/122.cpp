#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> cache(prices.size(),0);

        return recFind(prices,cache,0,-1);
    }

    int recFind(const vector<int>& prices, vector<int>& cache, int pos, int enter){

        if(pos == prices.size()-1){
            return enter>=0?prices[pos]-enter:0;
        }

        
        if(enter == -1){
            //not holding 

            if(cache[pos]!=0){
                return cache[pos];
            }
            //try enter

            int enterProfit= recFind(prices, cache,pos+1, prices[pos]);

            int noEnterProfit=(pos == prices.size()-1? 0:recFind(prices,cache,pos+1,-1));

            cache[pos] = max(enterProfit, noEnterProfit);
            return cache[pos];
        }
        
        //sell at this pos, or not

        if(prices[pos]<= enter){
            return recFind(prices,cache,pos+1,enter);
        }

        int sellRes = prices[pos] - enter + recFind(prices,cache, pos+1, -1);
        int notSellRes = recFind(prices,cache,pos+1,enter);

        return max(sellRes,notSellRes);

    }
};

int main(){
    Solution s;
    {
        vector<int> prices = {7,1,5,3,6,4};

        auto res = s.maxProfit(prices);
        assert(res == 7);
    }
    {
        vector<int> prices = {2,1,2,0,1};
        auto res = s.maxProfit(prices);
        assert(res == 2);
    }
}
