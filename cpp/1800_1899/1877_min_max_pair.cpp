#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int currentMax = 0;
        for(int i=0; i < nums.size()/2;++i){
            currentMax = max(currentMax, nums[i] + nums[nums.size()-i-1] );
        }
        return currentMax;
        
    }
};
