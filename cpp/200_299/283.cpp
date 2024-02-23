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
        auto res = copy_if(nums.begin(),nums.end(),nums.begin(),[](int v){
            return v!=0;
        });

        fill(res,nums.end(),0);

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
