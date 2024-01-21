#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {


        int head = 0;
        int tail = nums.size()-1;

        for(int idx = 0; idx < nums.size() && idx<= tail; ){
            if(nums[idx] == 0){
                swap(nums[head], nums[idx]);
                ++head;
                ++idx;
            } else if(nums[idx] == 2){
                swap(nums[tail], nums[idx]);
                --tail;
            } else {
                ++idx;
            }
        }
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {2,0,2,1,1,0};
        auto copy = nums;
        sort(copy.begin(),copy.end());
        s.sortColors(nums);
        assert(copy == nums);
    }
    {
        vector<int> nums = {2,0,1};
        auto copy = nums;
        sort(copy.begin(),copy.end());
        s.sortColors(nums);
        assert(copy == nums);
    }
}
