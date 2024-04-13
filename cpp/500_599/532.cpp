#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int ret = 0;

        for(int idx = 0; idx < nums.size(); ++idx){
            int v = nums[idx];

            if(idx >0 && v == nums[idx-1]){
                continue;
            }

            auto expect = v + k;

            if(binary_search(nums.begin()+ idx+1, nums.end(), expect)){
                ++ret;
            }
        }

        return ret;
        
    }
};
