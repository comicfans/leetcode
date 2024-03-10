#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {

        return rec(nums,0,k,1);
    }

    long long rec(const vector<int>& nums, int pos, int k, int sign){

        if(pos == nums.size()){
            assert(k == 0);
        }

        if(k == 0){
            return 0;
        }

        // pick start
        assert(pos +k <= nums.size());

        long long best = numeric_limits<long long>::min();

        for(int start = pos; start + k <= nums.size(); ++start){
            long currentSum = nums[start];
            for(int end = start + 1; end + (k-1) <= nums.size(); ++end){

                long long thisV = currentSum * k * sign;

                long long subV = rec(nums, end, k-1, -sign);

                long long totalV = thisV + subV;

                best = max(best ,totalV);

                if(end == nums.size()){
                    break;
                }
                currentSum += nums[end];
            }
        }

        assert(best != numeric_limits<long long>::min());
        return best;


    }
};

int main(){
    Solution s;
    
    {
        vector<int> nums = {12,-2,-2,-2,-2};
        int k = 5;
        assert(s.maximumStrength(nums,k) == 64);
    }
    {
        vector<int> nums =  {-1,-2,-3};
        int k = 1;
        assert(s.maximumStrength(nums,k) == -1);
    }
    {
        vector<int> nums = {1,2,3,-1,2};
        int k = 3;
        auto res = s.maximumStrength(nums,k) ;
        assert(res== 22);
    }
}
