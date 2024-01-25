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

        int halfSize = filter.size()/2;
        if(halfSize<=2){
            int ret = 0;
            for(int i = 0;i<halfSize;++i){
                ret+= (filter[i*2+1] -filter[i*2]);
            }
            return ret;
        }

        vector<int> leftMax(halfSize);
        vector<int> rightMax(halfSize);

        int leftEnterMin= 0;
        int rightExitMax = 0;
        for(int i = 0; i<halfSize; ++i){
            int rIdx = halfSize-1-i;
            if(i == 0){
                leftEnterMin= filter[i*2];
                leftMax[0]=filter[i*2+1]-leftEnterMin;
                rightExitMax = filter[rIdx*2+1];
                rightMax[rIdx] = rightExitMax - filter[rIdx*2];
                continue;
            }

            int tryLeft1 = filter[i*2+1] - filter[i*2];
            int tryLeft2 = filter[i*2+1] - leftEnterMin;
            leftMax[i] = max(tryLeft1,tryLeft2);
            leftMax[i] = max(leftMax[i],leftMax[i-1]);
            leftEnterMin = min(leftEnterMin,filter[i*2]);


            int tryRight1 = filter[rIdx*2+1] - filter[rIdx*2];
            int tryRight2= rightExitMax - filter[rIdx*2];

            rightMax[rIdx]= max(tryRight1,tryRight2);
            rightMax[rIdx]=max(rightMax[rIdx],rightMax[rIdx+1]);
            rightExitMax = max(rightExitMax, filter[rIdx*2+1]);
        }

        int res = 0;
        for(int i = 0; i<halfSize-1;++i){
            int thisSum = leftMax[i]+rightMax[i+1];
            res = max(res,thisSum);
        }

        return res;

        
    }
};

int main(){
    Solution s;
    {
        vector<int> prices={6,5,4,8,6,8,7,8,9,4,5};

        auto res = s.maxProfit(prices);
        assert(res == 7);
    }
    {
        vector<int> prices = {3,3,5,0,0,3,1,4};

        auto res = s.maxProfit(prices);
        assert(res == 6);
    }
    {
        vector<int> prices = {1,2,3,4,5};
        auto res = s.maxProfit(prices);
        assert(res == 4);
    }
    {
        vector<int> prices = {7,6,4,3,1};
        auto res = s.maxProfit(prices);
        assert(res == 0);
    }
}
