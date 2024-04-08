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
        int  inc = longestMonotonicSubarray1(nums);
        int  dec  = longestMonotonicSubarray2(nums);
        return max(inc,dec);
    }
    int longestMonotonicSubarray1(vector<int>& nums) {

        vector<int> cache(nums.size());

        int incBest = 1;

        for(int idx = 0; idx < nums.size(); ++idx){
            if(idx == 0){
                incBest = recInc(nums[0],nums, 1, cache)+1;
                continue;
            }


            int thisBest = 0;
            if(cache[idx] != 0){
                thisBest = cache[idx];
            }else{
                thisBest = recInc(nums[idx],nums,idx+1, cache)+1;
            }


            incBest = max(incBest, thisBest);
        }

        return incBest;

    }

    int longestMonotonicSubarray2(vector<int>& nums) {

        vector<int> cache(nums.size());

        int decBest = 1;

        for(int idx = 0; idx < nums.size(); ++idx){
            if(idx == 0){
                decBest = recDec(nums[0],nums, 1, cache)+1;
                continue;
            }

            

            int thisBest = 0;
            if(cache[idx] != 0){
                thisBest = cache[idx];
            }else{
                thisBest = recDec(nums[idx],nums,idx+1, cache)+1;
            }


            decBest= max(decBest, thisBest);
        }

        return decBest;
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
