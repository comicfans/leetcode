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
    int maxProfit(vector<int>& prices) {

        vector<int> buySubMax(prices.size(),-1);

        return recFind(prices, buySubMax,0, false, 0);
        
    }

    int recFind(const vector<int>& prices, vector<int>& buySubMax, int pos, bool holding,int enterPrice){

        if(pos >= prices.size()){
            return 0;
        }


        if(!holding){

            int buyRes ;
            if(buySubMax[pos] != -1){
                buyRes = buySubMax[pos];
            }else{
                buyRes = recFind(prices, buySubMax, pos+1, true, prices[pos]);
                buySubMax[pos] = buyRes;
            }

            //try buy at this pos


            int notBuyRes = recFind(prices,buySubMax,pos+1, false, 0);


            return max(buyRes, notBuyRes);
        }

        int holdRes = recFind(prices, buySubMax, pos+1, true, enterPrice);
        if(prices[pos] <= enterPrice ){
            return holdRes;
        }

        //sell at this pos, jump 2 pos;
        int sellRes =  recFind(prices, buySubMax, pos+2, false, 0) +  prices[pos] - enterPrice;

        return max(sellRes, holdRes);
    }
};

int main(){
    Solution s;
    {
        vector<int> p = {6,1,6,4,3,0,2};
        assert(s.maxProfit(p) == 7);
    }
    {
        vector<int> p = {1,2,3,0,2};

        assert(s.maxProfit(p) == 3);
    }
    {
        vector<int> p ={1};
        assert(s.maxProfit(p) == 0);
    }

    
}
