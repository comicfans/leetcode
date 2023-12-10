#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {

        sort(coins.begin(),coins.end());

        vector<bool> poss(target+1);

        recFill(coins,poss,target,0,0);


        //find which value we miss

        
        auto notReach = find(poss.begin()+1,poss.end(),false) ;
        int ret = 0;

        while(notReach != poss.end()){

            int toPut = notReach - poss.begin();

            for(int i =0;i< toPut; ++i){
                poss[i] = true;
            }

            coins.insert(coins.begin(),toPut);
            ++ret;

            recFill(coins, poss, target, 0, 0);

            sort(coins.begin(),coins.end());

            notReach = find(poss.begin()+1,poss.end(),false);
        }


        return ret;
        
        
    }

    void recFill(const vector<int>& coins, vector<bool>& poss,int target ,int currentPos, int sum){

        if(sum > target){
            return;
        }
        poss[sum] = true;

        for(int i = currentPos;i<coins.size();++i){
            int thisSum = sum + coins[i];
            if(thisSum > target){
                return;
            }
            if(poss[thisSum]){
                continue;
            }
            recFill(coins,poss,target,i+1,thisSum);
        }
    }
};

int main(){
    Solution s;
{
        vector<int> input = {5,6,7};
        assert(s.minimumAddedCoins(input,15) == 3);
    }
{
        vector<int> input = {1,1,1};
        assert(s.minimumAddedCoins(input,20) == 3);
    }
        {
        vector<int> input = {1,4,10};
        assert(s.minimumAddedCoins(input,19) == 2);
    }
    {
        vector<int> input = {1,4,10,5,7,19};
        assert(s.minimumAddedCoins(input,19) == 1);
    }
    
    

}
