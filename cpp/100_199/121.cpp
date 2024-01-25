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

        vector<pair<int,int>> leftMinRightMax(prices.size());

        for(int i = prices.size()-1;i>=0;--i){

            leftMinRightMax[prices.size()-1-i].first= prices[prices.size()-1-i]; 

            leftMinRightMax[i].second = prices[i]; 

            if(i != prices.size()-1){
                 leftMinRightMax[i].second= max(leftMinRightMax[i+1].second,leftMinRightMax[i].second);
                leftMinRightMax[prices.size()-1-i].first = min(leftMinRightMax[prices.size()-i-2].first,leftMinRightMax[prices.size()-i-1].first);
            }
        }

        int ret = 0;

        for(int i = 0;i<leftMinRightMax.size()-1;++i){

            int thisProfit = leftMinRightMax[i+1].second - leftMinRightMax[i].first;
            ret = max(ret,thisProfit);
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> prices = {7,1,5,3,6,4};

        auto res = s.maxProfit(prices);
        assert(res == 5);
    }
}
