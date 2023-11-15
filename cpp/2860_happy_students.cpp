#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        

        sort(nums.begin(),nums.end());

        int total = (nums[0] > 0);

        
        for(int idx = 0; idx < nums.size();++idx){
            int element = nums[idx];
            int thisTail = (upper_bound(nums.begin()+idx, nums.end(), element) - nums.begin());
            --thisTail;


            if (element >= thisTail+1){
                idx = thisTail;
                continue;
            }
            //this element can be placed in group
            if(thisTail == nums.size()-1){
                ++total;
            }else if (nums[thisTail+1] - thisTail > 1){
                ++total;
            }
            idx = thisTail;
        }

        return total;
    }

    
};

int main(int ,char**){

    Solution s;
    {
        vector seq{1,1};
        assert(s.countWays(seq)==2);
    }
    {
        vector seq{6,0,3,3,6,7,2,7};
        assert(s.countWays(seq)==3);
    }
}
