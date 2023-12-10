#include <cwchar>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        auto eq = equal_range(nums.begin(),nums.end(), target);

        if(eq.first == eq.second){
            return {-1,-1};
        }

        vector<int> ret = {(int)(eq.first - nums.begin()),
                           int(eq.second - nums.begin()-1)};
        return ret;

        
    }
};
