#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        map<int,int> cache;

        return rec(nums, target,cache);
        
    }

    int rec(vector<int>& nums, int target, map<int,int>& cache){
        auto hit= cache.find(target);
        if(hit!= cache.end()){
            return hit->second;
        }

        if(target == 0){
            return 1;
        }

        if(target < 0){
            return 0;
        }

        int ret = 0;
        for(int i = 0; i< nums.size(); ++i){

            int subCount = rec(nums, target - nums[i], cache);

            ret += subCount;
        }

        cache[target] = ret;
        return ret;

    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {1,2,3};
        assert(s.combinationSum4(nums,4) == 7);

    }
}
