#include <limits>
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
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        long long allSum = accumulate(nums.begin(),nums.end(),(long long)0);

        long long leftSum = 0;

        long long minMove = numeric_limits<int>::max();

        for(int i = 0; i< nums.size();++i){
            long long rightSum = allSum - leftSum - nums[i];
            long long leftMove = abs( (long long)i * nums[i]  -  leftSum );
            long long rightMove = abs( (long long)(nums.size() - 1 - i) * nums[i]  - rightSum);

            long long allMove = leftMove + rightMove;
            minMove = min(minMove, allMove);
            leftSum += nums[i];

        }
        return minMove;
        
    }
};

int main(){

    Solution s;
    {
        vector<int> nums = {1,10,2,9};
        assert(s.minMoves2(nums) == 16);
    }
    {
        vector<int> nums = {203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143};
        s.minMoves2(nums);
    }
}
