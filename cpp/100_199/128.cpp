#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.empty()){
            return 0;
        }

        int maxRes = 1;

        int res = 1;
        for(int idx = 1;idx<nums.size();++idx){
            if(nums[idx] == nums[idx-1]+1){
                ++res;
            }else if(nums[idx] == nums[idx-1]){
                continue;
            }else{
                maxRes = max(maxRes,res);
                res = 1;
            }
        }

        maxRes = max(res,maxRes);


        return maxRes;
        
    }
};
