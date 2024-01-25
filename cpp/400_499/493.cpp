#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        
        int rangeMin = nums[0];
        int rangeMax = nums[1];

        int ret = 0;
        for(int j = 1 ; j<nums.size();++j){

            long long thisLimit  = (long long)nums[j] * 2;

            if(thisLimit > rangeMax){
                rangeMin = min(rangeMin, nums[j]);
                rangeMax = max(rangeMax, nums[j]);
                continue;
            }

            int intLimit = nums[j]*2;
            int thisCount = count_if(nums.begin(),nums.begin()+j,[=](auto v){
                return v > intLimit;
            });

            ret += thisCount;

            rangeMin = min(rangeMin, nums[j]);
            rangeMax = max(rangeMax, nums[j]);
        }
        return ret;
    }
};
