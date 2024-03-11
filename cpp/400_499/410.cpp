#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#ifdef LEETCODE
#include "../parse.h"
#endif

using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int allSum = accumulate(nums.begin(),nums.end(), 0);
        map<int,map<int,int>> cache;
        return rec(nums, 0, k, cache, allSum);
    }

    int rec(const vector<int>& nums, int beginEle, int k,map<int,map<int,int>>& cache, const int leftSum){

        assert(k!=0);

        if(k == 1){
            return accumulate(nums.begin()+ beginEle, nums.end(), 0);
        }

        auto pos = cache[beginEle].find(k);
        if(pos!= cache[beginEle].end()){
            return pos->second;
        }

        int subBest =numeric_limits<int>::max();
        int expectSum = leftSum / k;

        int sum = 0;

        int chooseEnd = beginEle +1;
        for(int end = chooseEnd ;end <= nums.size() - (k-1) ; ++end){
            sum += nums[end - 1];
            if(sum == expectSum){
                chooseEnd = end;
                break;
            }

            if(sum > expectSum){
                chooseEnd = max(beginEle +1 , end - 1);
                if(chooseEnd < end){
                    sum -= nums[end-1];
                }
                break;
            }

            chooseEnd = end;
        }


        for(int end = chooseEnd; end <= nums.size() - (k-1) ; ++end){

            int sub = rec(nums,end, k-1, cache, leftSum - sum);

            int thisRes = max(sub, sum);

            if(thisRes > subBest){
                break;
            }

            subBest = min(thisRes, subBest);
            sum += nums[end];
            if(sum > subBest){
                break;
            }
        }

        cache[beginEle].insert({k, subBest});
        return subBest;
    }
};

int main(){
    Solution s;
    {
        VI nums = {1,4,4};
        auto res = s.splitArray(nums, 3);
        assert(res == 4);
    }
    {
        VI nums = {7,2,5,10,8};
        auto res = s.splitArray(nums, 2);
        assert(res == 18);
    }
}
