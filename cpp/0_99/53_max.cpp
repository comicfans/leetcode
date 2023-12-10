#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentBest = nums[0];


        int currentSum = currentBest;

        for(int i = 1;i<nums.size();++i){

            if(nums[i]>=0){
                currentSum += nums[i];
                int currentCompare = max(currentSum, nums[i]);
                currentSum = currentCompare; 
                currentBest = max(currentBest, currentCompare);
                continue;
            }

            //nums <0
            //
            currentSum = currentSum + nums[i];
            currentSum = max(currentSum, nums[i]);
            currentBest  = max(currentBest, currentSum);
            if(currentSum < 0){
                currentSum = 0;
                continue;
            }
            // has negative, try next postive


        }
        return currentBest;
    }

    
};

int main(){
    Solution s;
    {
        vector<int> input = {-2,-1};
        assert(s.maxSubArray(input)==-1);
    }
    {
        vector<int> input = {-1,1,2,1};
        assert(s.maxSubArray(input) == 4);
    }
}
