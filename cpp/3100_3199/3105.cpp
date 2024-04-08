#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int maxInc = 1;
        int maxDec = 1;

        int currentInc = 1;
        int currentDec = 1;


        for(int i = 1;i < nums.size(); ++i){
            int v = nums[i];

            if(v == nums[i-1]){
                maxInc = max(maxInc, currentInc);
                maxDec = max(maxDec, currentDec);
                currentInc = 1;
                currentDec = 1;
                continue;
            }

            if(v > nums[i-1]){
                ++currentInc;

                maxDec = max(maxDec, currentDec);
                currentDec = 1;
                continue;
            }

            ++currentDec;
            maxInc = max(maxInc, currentInc);
            currentInc = 1;
        }

        maxInc = max(maxInc, currentInc);
        maxDec = max(maxDec, currentDec);

        return max(maxInc,maxDec);
    }

   

    int recDec(int prev, const vector<int>& nums, int idx, vector<int>& cache){

        if(idx == nums.size()){
            return 0;
        }

        if(nums[idx]>= prev){
            return 0;
        }


        //pick it or not

        int pickRes = 0;
        if(cache[idx]!=0){
            pickRes = cache[idx];
        }else{
            pickRes = recDec(nums[idx],nums, idx+1, cache);
            ++pickRes;
            cache[idx] = pickRes;
        }

        return pickRes;
    }

    int recInc(int prev, const vector<int>& nums, int idx, vector<int>& cache){

        if(idx == nums.size()){
            return 0;
        }

        if(nums[idx]<= prev){
            return 0;
        }


        //pick it or not

        int pickRes = 0;
        if(cache[idx]!=0){
            pickRes = cache[idx];
        }else{
            pickRes = recInc(nums[idx],nums, idx+1, cache);
            ++pickRes;
            cache[idx] = pickRes;
        }

        return pickRes;

    }

    
};

int main(){
    Solution s;
    {


        vector<int> nums=  {1,5,2,7};
        auto res = s.longestMonotonicSubarray(nums);
        assert(res == 2);
    }
    {

        vector<int> nums=  {6,6,3};

        auto res = s.longestMonotonicSubarray(nums);
        assert(res == 2);
    }
    {
        vector<int> nums=  {1,4,3,3,2};

        auto res = s.longestMonotonicSubarray(nums);
        assert(res == 2);
    }
    {
        vector<int> nums=  {3,3,3,3};

        auto res = s.longestMonotonicSubarray(nums);
        assert(res == 1);
    }
    {
        vector<int> nums=  {3,2,1};

        auto res = s.longestMonotonicSubarray(nums);
        assert(res == 3);
    }
}
