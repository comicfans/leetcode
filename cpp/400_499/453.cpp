#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int delta = 0;

        int currentMin = nums[0];
        for(int i = 1; i< nums.size(); ++i){
            if(nums[i] >= currentMin){
                delta += (nums[i] - currentMin);
                continue;
            }
           
            delta += (currentMin - nums[i]) * i;
            currentMin = nums[i];
        }
        return delta;
    }
};
