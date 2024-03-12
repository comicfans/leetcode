#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#ifdef LEETCODE
#include "../parse.h"
#endif

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<int> cumsum(nums.size());
     
        for(int i = 0;i< nums.size();++i){
            cumsum[i]= nums[i] + (i==0?0:cumsum[i-1]);
        }

        if(cumsum.back() %2 ==1 ){
            return false;
        }

        int half = cumsum.back() /2;
        // 1, 5, 5, 11
        //
        return rec(nums,0, half,cumsum);
        
    }

    bool rec(const vector<int>& nums, int pos, int target, const vector<int>& cumsum){

        if(pos == nums.size()){
            return false;
        }

        if(target == 0){
            return true;
        }

        if(target < nums[pos]){
            return false;
        }

        int leftPossible = cumsum.back() - (pos==0?0: cumsum[pos -1]);
        if(leftPossible < target){
            return false;
        }

        if(leftPossible == target){
            return true;
        }

        for(int tryPos = pos ; tryPos < nums.size();){

            if(rec(nums,tryPos +1, target - nums[tryPos], cumsum)){
                return true;
            }

            tryPos = upper_bound(nums.begin()+ tryPos+1, nums.end(), nums[tryPos]) - nums.begin();
        }


        return false;

    }
};

int main(){
    Solution s;
    {
        VI nums = {23,13,11,7,6,5,5};
        assert(s.canPartition(nums));
    }
    {
        VI nums = {1,2,5};

        assert(!s.canPartition(nums));
    }
    {

        VI nums = {4,4,4,4,4,4,4,4,8,8,8,8,8,8,8,8,12,12,12,12,12,12,12,12,16,16,16,16,16,16,16,16,20,20,20,20,20,20,20,20,24,24,24,24,24,24,24,24,28,28,28,28,28,28,28,28,32,32,32,32,32,32,32,32,36,36,36,36,36,36,36,36,40,40,40,40,40,40,40,40,44,44,44,44,44,44,44,44,48,48,48,48,48,48,48,48,52,52,52,52,52,52,52,52,56,56,56,56,56,56,56,56,60,60,60,60,60,60,60,60,64,64,64,64,64,64,64,64,68,68,68,68,68,68,68,68,72,72,72,72,72,72,72,72,76,76,76,76,76,76,76,76,80,80,80,80,80,80,80,80,84,84,84,84,84,84,84,84,88,88,88,88,88,88,88,88,92,92,92,92,92,92,92,92,96,96,96,96,96,96,96,96,97,99};

        s.canPartition(nums);
    }
}
