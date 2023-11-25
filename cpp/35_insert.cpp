#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        auto pos = lower_bound(nums.begin(),nums.end(),target);

        return pos - nums.begin();
        
    }
};
