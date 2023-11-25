#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size()<=3){

            auto pos = find(nums.begin(),nums.end(), target);
            if(pos ==  nums.end()){
                return -1;
            }

            return pos -nums.begin();
        }

            if(nums.front()< nums.back()){
                //not rotated
                auto eq = equal_range(nums.begin(),nums.end(), target);
                if(eq.first == eq.second){
                    return -1;
                }
                return eq.first - nums.begin();
            }

            auto rotate = recFind(nums,0,nums.size());

            if(target >= nums.front()){
                auto pos = equal_range(nums.begin(), nums.begin() + rotate,target);
                return pos.first == pos.second ? -1: pos.first - nums.begin();
            }else{
                auto pos = equal_range(nums.begin() + rotate, nums.end(),target);
                return pos.first == pos.second ? -1: pos.first - nums.begin();
            }

        }

    int recFind(const vector<int>& nums, int beginIdx, int endIdx){

        auto pickCenter = (beginIdx + endIdx) / 2;
        if(pickCenter == beginIdx){
            return endIdx;
        }


        if(nums[pickCenter]> nums[beginIdx]){
            return recFind(nums, pickCenter, endIdx);
        }

        return recFind(nums,beginIdx, pickCenter);
    }
};

int main(){

    Solution s;
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 0;
        assert(s.search(nums,target) == 4);
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 3;
        assert(s.search(nums,target) == -1);
    }
    {
        vector<int> nums = {1};
        int target = 0;
        assert(s.search(nums,target) == -1);
    }
    {
        vector<int> nums = {9,0,2,7,8};
        int target = 3;
        assert(s.search(nums,target) == -1);
    }
}
