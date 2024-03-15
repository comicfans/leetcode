#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ret;
        for(int i = 1;i< nums.size(); ++i){
            if(nums[i]==nums[i-1]){
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};
