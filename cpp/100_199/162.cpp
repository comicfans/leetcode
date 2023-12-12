#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return recFind(nums, 0, nums.size());
    }

    int recFind(const vector<int>& nums,int begin,int end){

        int mid = (begin + end )/2;

        bool gtLeft = (mid == 0?true:nums[mid]>nums[mid-1]);

        bool gtRight = (mid == nums.size()-1? true: nums[mid]>nums[mid+1]);

        if(gtLeft && gtRight){
            return mid;
        }

        if(!gtLeft){
            return recFind(nums,begin,mid);
        }

        return recFind(nums,mid+1, end);
    }
};
