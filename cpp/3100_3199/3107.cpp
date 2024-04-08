#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        //2 5 5 6 8
        //4
        //
        //2 5 5 6 8
        //    7
        //
        //1 2 3 4 5 6

        int medIdx = nums.size() / 2;

        int currentMed = nums[medIdx];
        if(currentMed == k){
            return 0;
        }

        if(currentMed > k){

            auto lower = upper_bound(nums.begin(), nums.begin() + medIdx, k) - nums.begin();

            long long sum = accumulate(nums.begin() + lower, nums.begin() + medIdx + 1, (long long)0);

            return sum - (long long)k * (medIdx + 1 - lower);

        }

        auto upper = upper_bound(nums.begin() +medIdx, nums.end(), k) - nums.begin();

        auto sum =accumulate(nums.begin()+medIdx, nums.begin() + upper, (long long)0);

        return (long long)k * (upper - medIdx) - sum;

    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {2,5,6,8,5};
        auto res = s.minOperationsToMakeMedianK(nums, 4);

        assert(res == 2);
    }
    {
        vector<int> nums = {2,5,6,8,5};
        auto res = s.minOperationsToMakeMedianK(nums, 7);

        assert(res == 3);
    }
}
