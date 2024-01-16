#include <cmath>
#include <cstdint>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {


        vector<int> ret(nums.size());

        uint32_t maxV = pow(2,maximumBit) - 1;

        uint32_t xorRes = 0;

        for(int i = 0; i< nums.size(); ++i){
            xorRes = xorRes xor nums[i];
            ret[nums.size()-1 - i] = maxV xor xorRes;
        }

        return ret;
        
    }
};
