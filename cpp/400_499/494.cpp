#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        vector<pair<int,int>> numberCount;

        for(int pos = 0; pos < nums.size(); ){

            auto end = upper_bound(nums.begin() + pos + 1, nums.end(), nums[pos]) - nums.begin();

            numberCount.push_back({nums[pos], end - pos});
            pos = end;
        }
        



        return rec(numberCount, 0, target);
        
    }

    int rec(const vector<pair<int,int>>& numCount, int pos, int target){

        if(pos == numCount.size()){

            if(target == 0){
                return 1;
            }

            return 0;
        }

        int value = numCount[pos].first;
        int count = numCount[pos].second;

        int ret = 0;

        int zeroSub = 0;
        for(int i = 0; i<= count; ++i){

            int thisValue = (i  - (count - i)) * value;

            int left = target - thisValue;
            
            auto temp = pos;
            ++temp;

            int sub ;
            if(value == 0 && i!= 0){
                sub = zeroSub;
            }else{
                sub = rec(numCount, temp, left);
                zeroSub = sub;
            }

            if(value == 0 && zeroSub == 0){
                return 0;
            }


            if(sub == 0){
                continue;
            }

            if(value == 0){
                ret = pow(2, count) * sub;
                break;
            }

            //pick i=4 out of count=5
            //
            // 5*4*3*2 / 4*3*2*1 = 
            //
            //
            // choose i out of count
            // !count /  !i  / !(count - i)
            int res = 1;
            int big = max(i, count - i);
            int small = min(i, count - i);
            for(int j = count; j > big; --j){
                res *= j;
                if(small > 1 && res % small == 0){
                    res /= small;
                    --small;
                }
            }

            while(small > 1){
                assert(res % small == 0);
                res /= small;
                --small;
            }

            ret += res * sub;

            
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {9,7,0,3,9,8,6,5,7,6};

        auto res = s.findTargetSumWays(nums, 2);
        assert(res == 40);
    }
    {
        vector<int> nums = {0,0,0,0,0,0,0,0,1};
        auto res = s.findTargetSumWays(nums, 1);
        assert(res == 256);
    }
    {
        vector<int> nums = {1};
        auto res = s.findTargetSumWays(nums, 1);
        assert(res == 1);
    }
    {
        vector<int> nums = {1,1,1,1,1};
        auto res = s.findTargetSumWays(nums, 3);
        assert(res == 5);
    }
}
