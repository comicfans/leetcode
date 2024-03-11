#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        int ret = 0;

        int delta = nums[1] - nums[0];
        int count = 1;

        for(int i = 2; i< nums.size(); ++i){
            int thisDelta = nums[i] - nums[i-1];
            if(thisDelta == delta){
                ++count;
                if(count >= 2){
                    ret +=  (count - 1);
                }
            }else{
                delta =thisDelta;
                count = 1;
            }
        }



        return ret;
    }
};
