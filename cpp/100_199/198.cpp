#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }

        vector<int> cache(nums.size(),-1);

        int robFirst = recRob(nums,0,cache);
        int robSecond = recRob(nums,1,cache);

        return max(robFirst,robSecond);

    
    }

    int recRob(const vector<int>& nums, int start, vector<int>& cache){

        if(start >= nums.size()){
            return 0;
        }

        if(cache[start]!=-1){
            return cache[start];
        }

        int robThis = nums[start];

        // r  e   r  r  r  ?
        //    1   2  3  4 
        int subBest = 0;
        for(int offset = 2; offset <=3 ; ++offset){
            int sub = recRob(nums,start + offset,cache);
            subBest = max(sub,subBest);
        }

        cache[start] = robThis + subBest;
        return cache[start];

    }
};
