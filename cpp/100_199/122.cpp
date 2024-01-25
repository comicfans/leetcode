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

        int ret = 0;

        for(int i = 1;i<filter.size();i+=2){
            ret += (filter[i] - filter[i-1]);
        }

       
        return ret;
        
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
