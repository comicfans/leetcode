#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int zeroEnd = -1;
        for(int check = 0; check < nums.size(); ++check){

            if(nums[check] != 0){
                continue;
            }



            if(zeroEnd == -1){
                zeroEnd = find_if(nums.begin()+check+1,nums.end(),[](int v){
                    return v!=0;
                }) - nums.begin();
            }else{
                zeroEnd = find_if(nums.begin()+zeroEnd, nums.end(),[](int v){
                    return v!=0;
                }) - nums.begin();
            }

            if(zeroEnd == nums.size()){
                break;
            }

            swap(nums[check],nums[zeroEnd]);
            zeroEnd++;


        }


    }
};

int main(){
    Solution s;
    {
vector<int> nums = {0,1,0,3,12};
vector<int> expect =  {1,3,12,0,0};
 s.moveZeroes(nums);
assert(nums == expect);
}{

        vector<int> nums = {0};
        vector<int> expect= {0};
        s.moveZeroes(nums);
        assert(nums == expect);
    }
}
