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

        multiset<int> window(nums.begin(),nums.begin()+k);

        vector<int> ret(nums.size() - k+1);
        ret.front() = *(--window.end());

        for(int i = 1; i<= nums.size() -k; ++i){
            auto pos = window.find(nums[i-1]);
            window.erase(pos);

            window.insert(nums[i+k-1]);

            ret[i] = *(--window.end());
        }


        return ret;
    }
};

int main(){
    Solution s;
{
        vector<int> nums = {-7,-8,7,5,7,1,6,0};
        int k = 4;
        vector<int> expect  = {7,7,7,7,7};
        auto res = s.maxSlidingWindow(nums,k);
        assert(res == expect);
    }
    {
        vector<int> nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        vector<int> expect  = {3,3,5,5,6,7};
        auto res = s.maxSlidingWindow(nums,k);
        assert(res == expect);
    }
}
