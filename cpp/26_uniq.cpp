#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        auto pos = unique(nums.begin(),nums.end());
        return pos - nums.begin();
        
    }
};
