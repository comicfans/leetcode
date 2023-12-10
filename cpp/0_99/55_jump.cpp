#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int prevMaxReach = -1;
        int maxReach = 0;

        while(maxReach > prevMaxReach){

            int thisReachMax = maxReach;
            for(int i = prevMaxReach + 1;i <= min<int>(maxReach,nums.size()-1);++i){
                thisReachMax = max(nums[i] + i,thisReachMax);
            }

            prevMaxReach = maxReach;
            maxReach = thisReachMax;
        }

        return maxReach >= nums.size() - 1;
       
    }
};
