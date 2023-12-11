#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {



        int diffCount = 0;
        int lastSegmentBegin = 0;
        int lastSegmentEnd = 0;

        for(int i = 0;i< nums.size();++i){

            int sameIdx = nums.size();
            for(int j = sameIdx - 1;j >= i ;--j){
                if(nums[j] == nums[i]){
                    sameIdx = j;
                    break;
                }
            }

            if (sameIdx <= lastSegmentEnd){
                continue;
            }

            //newRange exceeds prev range

            if(i >  lastSegmentEnd){
                ++diffCount;
                lastSegmentBegin = i;
                lastSegmentEnd = sameIdx;
                continue;
            }

            lastSegmentEnd = sameIdx;
        }



        int base = 1;

        int mod = pow(10,9)+7;
        for(int po = 0;po<diffCount-1;++po){

            int thisV = (base * 2) % mod;

            base = thisV;

        }

        return base;
    }
};

int main(){
    Solution s;
    {

        vector<int> input = {1,5,1,5,6};
        assert(s.numberOfGoodPartitions(input) == 2);
    }
    {
        vector<int> input = {2,3,2,8,8};
        assert(s.numberOfGoodPartitions(input) == 2);
    }
    {
        vector<int> input = {1,2,3,4};
        assert(s.numberOfGoodPartitions(input) == 8);
    }
    {
        vector<int> input = {1,1,1,1};
        assert(s.numberOfGoodPartitions(input) == 1);
    }
    {
        vector<int> input = {1,2,1,3};
        assert(s.numberOfGoodPartitions(input) == 2);
    }
}
