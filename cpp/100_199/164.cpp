#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i =1;i<nums.size();++i){
            res = max(res, nums[i]-nums[i-1]);
        }
        return res;
    }
};
