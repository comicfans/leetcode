#include <vector>
#include <array>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {

        array<int,2> empty;
        fill(empty.begin(),empty.end(),-1);
        vector<array<int,2>> cache(nums.size(),empty);
        auto robFrom0 = recRob(nums,0,cache, true);
        auto robFrom1 = recRob(nums,1,cache,false);

        return max(robFrom0,robFrom1);
        
    }

    int recRob(const vector<int>& nums, int pos, vector<array<int,2>>& cache, bool rob0){

        if(nums.size()==1){
            return nums[0];
        }

        if(pos >= nums.size()){
            return 0;
        }

        if(cache[pos][rob0]!=-1){
            return cache[pos][rob0];
        }

        if(pos == nums.size()-1){
            cache[pos][rob0] = rob0?0:nums[pos];
            return cache[pos][rob0];
        }

        int robThis = nums[pos]+ recRob(nums, pos+2, cache, rob0);

        int noRobThis = recRob(nums,pos+1,cache, rob0);

        int best = max(robThis,noRobThis);

        cache[pos][rob0] = best;
        return best;

    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {2,3,2};
        assert(s.rob(nums)==3);
    }{
        vector<int> nums = {1,2,3,1};
        assert(s.rob(nums)==4);
    }
}
