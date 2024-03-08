#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        if(nums.size()<=1){
            return nums.size();
        }

        int delta = nums[1] - nums[0];

        int idx = 2;
        for(;delta == 0 && idx < nums.size(); ++idx){
            delta = nums[idx] - nums[idx-1];
        }

        if(idx == nums.size()){
            if(delta== 0){
                return 1;
            }
            return 2;
        }

        int res = 2;

        for(;idx < nums.size(); ++idx){
            int thisDelta = nums[idx] - nums[idx-1];
            if(thisDelta == 0){
                continue;
            }

            if(thisDelta * delta > 0){
                continue;
            }

            delta = thisDelta;
            ++res;
        }

        return res;
    }
};

int main(){
    Solution s;
    {
        vector<int> nums={1,7,4,9,2,5};
        assert(s.wiggleMaxLength(nums) == 6);
    }
}
