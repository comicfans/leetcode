#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {


        return rec(nums, 0, target);
        
    }

    int rec(const vector<int>& nums, int pos, int target){

        if(pos == nums.size()){

            if(target == 0){
                return 1;
            }

            return 0;
        }

        int addRes = rec(nums, pos+1, target - nums[pos]);

        int subRes = rec(nums, pos+1, target + nums[pos]);

        return addRes + subRes;


    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {9,7,0,3,9,8,6,5,7,6};

        auto res = s.findTargetSumWays(nums, 2);
        assert(res == 40);
    }
    {
        vector<int> nums = {0,0,0,0,0,0,0,0,1};
        auto res = s.findTargetSumWays(nums, 1);
        assert(res == 256);
    }
    {
        vector<int> nums = {1};
        auto res = s.findTargetSumWays(nums, 1);
        assert(res == 1);
    }
    {
        vector<int> nums = {1,1,1,1,1};
        auto res = s.findTargetSumWays(nums, 3);
        assert(res == 5);
    }
}
