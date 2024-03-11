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
        map<int,map<int,int>> cache;
        return rec(nums, 0, k, cache);
    }

    int rec(const vector<int>& nums, int beginEle, int k,map<int,map<int,int>>& cache){

        assert(k!=0);

        if(k == 1){
            return accumulate(nums.begin()+ beginEle, nums.end(), 0);
        }

        auto pos = cache[beginEle].find(k);
        if(pos!= cache[beginEle].end()){
            return pos->second;
        }

        int subBest =numeric_limits<int>::max();

        int sum = 0;

        for(int end = beginEle +1; end <= nums.size() - (k-1) ; ++end){
            sum += nums[end - 1];

            int sub = rec(nums,end, k-1, cache);

            int thisRes = max(sub, sum);

            subBest = min(thisRes, subBest);
        }

        cache[beginEle].insert({k, subBest});
        return subBest;
    }
};

int main(){
    Solution s;
    {
        VI nums = {7,2,5,10,8};
        auto res = s.splitArray(nums, 2);
        assert(res == 18);
    }
}
