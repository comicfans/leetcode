#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    long long countAlternatingSubarrays(vector<int>& nums) {

        auto numberN = [](int i){
            return ((long long)i + 1) * i /2;
        };


        long long res = 0;
        int maxLength = 1;

        for(int i = 1;i < nums.size(); ++i){

            if(nums[i]!= nums[i-1]){
                ++maxLength;
                continue;
            }

            auto thisSub =numberN (maxLength);

            res += thisSub;

            maxLength = 1;
        }

        res += numberN(maxLength);

        return res;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {1,0,1,0};
        auto res = s.countAlternatingSubarrays(nums);
        assert(res == 10);
    }
    {
        vector<int> nums = {0,1,1,1};
        auto res = s.countAlternatingSubarrays(nums);
        assert(res == 5);
    }

}
