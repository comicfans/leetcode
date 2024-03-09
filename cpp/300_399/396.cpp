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
    int maxRotateFunction(vector<int>& nums) {
        //F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
        //F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16 
        //6x(0-3) + 2x(3-2) + 3* (2-1) + 4* (1-0)  from 1~n-1, sum   -3n 
        //4+3+2 - (size-1) * 6 = 9 - 18  = -9
        //
        //6+4+3 - 3*2 = 7
        //F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
        //
        //2+6+4 - 3x3 
        //F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
        
        int allSum = 0;
        int bestSum = 0;
        for(int i = 0;i<nums.size(); ++i){
            bestSum += i*nums[i];
            allSum += nums[i];
        }

        int prevSum = bestSum;
        for(int thisEndIdx = nums.size()-2; thisEndIdx >= 0; --thisEndIdx){

            const int prevEnd = nums[thisEndIdx+1];
            int nextSum = prevSum + allSum - nums.size()* prevEnd;

            bestSum = max(bestSum, nextSum);
            prevSum = nextSum;
        }

        return bestSum;

    }
};
int main(){
    Solution s;
    {
        vector<int> nums = {4,3,2,6};
        assert(s.maxRotateFunction(nums) == 26);
    }
    {
        vector<int> nums = {100};
        assert(s.maxRotateFunction(nums) == 0);
    }
}
