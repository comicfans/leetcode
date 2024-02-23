#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> window(nums.begin(),nums.begin()+k);
        sort(window.begin(),window.end());

        vector<int> ret(nums.size() - k+1);
        ret.front() = window.back();

        for(int i = 1; i<= nums.size() -k; ++i){
            auto erPos = lower_bound(window.begin(),window.end(),nums[i-1]);

            window.erase(erPos);
            auto insPos= lower_bound(window.begin(),window.end(),nums[i+k-1]) ;

            window.insert(insPos, nums[i+k-1]);

            ret[i] = window.back();
        }


        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        vector<int> expect  = {3,3,5,5,6,7};
        auto res = s.maxSlidingWindow(nums,k);
        assert(res == expect);
    }
}
