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
    int minimumCoins(vector<int>& prices) {

        int currentSpend = 0;
        int maxFreeIndex = -1;
        return recFind(prices, 0, currentSpend, maxFreeIndex);
        
    }

    int recFind(vector<int>& prices, int currentPos, int currentSpend, int maxFreeIndex){

        if((currentPos == prices.size())|| (maxFreeIndex >= (int)prices.size()-1)){
            return currentSpend;
        }



        if(currentPos <= maxFreeIndex){
            //can be taken freely
            recFind(prices, currentPos +1, currentSpend, maxFreeIndex, posBest);
        }


        { 

            int tryBuySpend = currentSpend + prices[currentPos];
            int newMaxFreeIndex = currentPos * 2+1;
            if(newMaxFreeIndex > maxFreeIndex){
                recFind(prices, currentPos + 1, tryBuySpend,newMaxFreeIndex);
            }
        }
    
    }
};

int main(){
    Solution s;
{
        vector<int> p = {3,1,2};
        assert(s.minimumCoins(p) == 4);
    }
{
        vector<int> p = {1,10,1,1};
        auto res = s.minimumCoins(p);
        assert(res == 2);
    }
    
    {
         vector<int> p = {38,23,27,32,47,45,48,24,39,26,37,42,24,45,27,26,15,16,26,6};

        auto res = s.minimumCoins(p);
        assert(res == 132);
    }
}
