#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {


        int best = numeric_limits<int>::max();
        
       
        int begin = 0;
        int end = begin+1;
        int currentSum = nums[0];
        while((begin < nums.size()) && (end <= nums.size())){

            if(currentSum >= target){
                best = min(best, end - begin);
                currentSum -= nums[begin];
                ++begin;
                continue;
            }
            //not enough
            //
            ++end;
            if(end > nums.size()){
                break;
            }
            currentSum += nums[end - 1];
        }

        return best == numeric_limits<int>::max()?-1:best;
        
    }
};

int main(){
    Solution s;

    {
        vector<int> nums = {2,3,1,2,4,3};
        assert(s.minSubArrayLen(7,nums) == 2);
    }

}
