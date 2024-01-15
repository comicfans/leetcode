#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        

        // 1,2,3,4,5,6,7,8
        //
        //
        // 1   2   3
        //   4   5    6


        vector<int> ret(nums.size());

        int offset = 0;
        if(ret.size()%2!= 0){
            offset = 1;
            ret[0] = nums.back();
        }

        for(int i =0;i<nums.size()/2;++i){
            ret[offset+i*2] = nums[i];
            ret[offset+i*2+1] = nums[nums.size()/2+i];
        }
        
        return ret;
    }
};

int main(){

    Solution s;
    {
        vector<int> nums = {1,2,5,9};
        s.rearrangeArray(nums);
    }
    {
        vector<int> nums = {1,2,3,4,5};
        s.rearrangeArray(nums);
    }
    {
        vector<int> nums = {1,5,2,6,3,7,4,8};
        s.rearrangeArray(nums);
    }
}
