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

        vector<int> filter;

        bool searchLow = true;
        for(int i = 0; i < prices.size();++i){

            if(searchLow){


                if(i>0 && prices[i]>prices[i-1]){
                        continue;
                }

                if(i <prices.size()-1 && prices[i]>= prices[i+1]){
                    continue;
                }

                filter.push_back(prices[i]);
                searchLow = false;

                continue;
            }
            
            if(i>0 && prices[i]<prices[i-1]){
                continue;
            }
            if(i < prices.size() - 1 && prices[i] <= prices[i+1]){
                continue;
            }
            filter.push_back(prices[i]);
            searchLow = true;
        }

        if(!searchLow){
            filter.pop_back();
        }


        assert(filter.size()%2==0);
        if(filter.empty()){
            return 0;
        }

        int halfSize = filter.size()/2;
        vector<pair<int,int>> leftMinRightMax(halfSize);


        for(int i = 0;i<halfSize;++i){

            int rIdx = halfSize-1 - i;
            leftMinRightMax[i].first = filter[i*2];
            leftMinRightMax[rIdx].second = filter[rIdx*2+1];

            if(i==0){
                continue;
            }

            leftMinRightMax[i].first = min(leftMinRightMax[i].first, leftMinRightMax[i-1].first);
            leftMinRightMax[rIdx].second = max(leftMinRightMax[rIdx].second, leftMinRightMax[rIdx+1].second);
        }


        int ret = 0;

        for(int i = 0;i<halfSize;++i){

            int thisProfit = leftMinRightMax[i].second - leftMinRightMax[i].first;
            ret = max(ret,thisProfit);
        }

        return ret;
        
    }
};

int main(){
    Solution s;
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
