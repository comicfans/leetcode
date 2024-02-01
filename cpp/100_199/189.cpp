#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

int gcd(int small,int big){
    int mod = big % small;
    if(mod == 0){
        return small;
    }

    return gcd(mod,small);
}

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        if(k == 0){
            return;
        }

        int offset = 0;
        int offMax = 1;
        int changeCount = nums.size() ;

        int g = gcd(k, nums.size());
        offMax = g;
        changeCount = nums.size() / g ;
        


        for(int offset = 0; offset < offMax; ++offset){

        int temp = nums[nums.size() + offset - k];
        int currentIdx = offset;

        for(int step = 0; step < changeCount; ++step){

            int nextIdx = (currentIdx + k) % nums.size();
            swap(nums[currentIdx], temp);

            currentIdx = nextIdx;
        }
        }

        
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {1,2,3,4,5,6};
        int k =4;
        vector<int> expect = {3,4,5,6,1,2};
        s.rotate(nums,k);
        assert(nums == expect);
    }
    {
        vector<int> nums = {-1,-100,3,99};
        int k = 2;
        vector<int> expect =  {3,99,-1,-100};
        s.rotate(nums,k);
        assert(nums == expect);
    }
    {
        vector<int> nums = {1,2,3,4,5,6,7};
        int k = 3;
        vector<int> expect =  {5,6,7,1,2,3,4};
        s.rotate(nums,k);
        assert(nums == expect);
    }
}
