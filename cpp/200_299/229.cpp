#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ret;
        for(int pos = 0; pos != nums.size();){
            auto range = equal_range(nums.begin()+pos,nums.end(),nums[pos]);
            if(range.second - range.first > nums.size()/3){
                ret.push_back(nums[pos]);
            }
            pos = range.second - nums.begin();
        }
        return ret;
    }
};
