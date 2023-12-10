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
    int maxCoins(vector<int>& nums) {

        int sum = 0;
        while(!nums.empty()){


            int maxDelta = numeric_limits<int>::min();
            int chooseIdx = -1;
            int delta = 0;
            for(int pickIdx = 0;pickIdx < nums.size(); ++pickIdx){

                int thisDelta = nums[pickIdx] * (pickIdx ==0? 1:nums[pickIdx-1]) * (pickIdx == nums.size()-1 ? 1:nums[pickIdx + 1]) - nums[pickIdx];

                if(thisDelta > maxDelta){
                    maxDelta = thisDelta;
                    delta = thisDelta + nums[pickIdx];
                    chooseIdx = pickIdx;
                }
            }

            sum += delta;
            nums.erase(nums.begin()+chooseIdx);
        }

        return sum;
    }

    int slow(vector<int>& nums){

        vector<int> pick;
        for(int i=0;i<nums.size();++i){
            pick.push_back(i);
        }

        int best = numeric_limits<int>::min();
        vector<int> bestPick;
        do{
            int thisSum = 0;
            vector<int> copyNums = nums;
            vector<int> copyPick = pick;
            for(int pickIdx = 0;pickIdx < pick.size();++pickIdx){

                auto idx = copyPick[pickIdx];

                int thisDelta = copyNums[idx] * (idx ==0? 1:copyNums[idx-1]) * (idx == copyNums.size()-1 ? 1:copyNums[idx+1]) ;


                thisSum += thisDelta;

                for(auto & v: copyPick){
                    if(v>idx){
                        --v;
                    }
                }
                copyNums.erase(copyNums.begin()+ idx);
            }

            best = max(thisSum, best);
            if(best == thisSum){
                bestPick = pick;
            }

        }while(next_permutation(pick.begin(),pick.end()));
        

        return best;
    }
};

int main(){
    Solution s;

    {
        vector<int> input = {5,2,4,51,2,3};
        auto slowRes = s.slow(input);
        auto quickRes= s.maxCoins(input);
        assert(slowRes == quickRes);

    }
}
