#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int pos = 0;
        while(pos != nums.size()){
            int up = upper_bound(nums.begin()+pos+1,nums.end(),nums[pos]) - nums.begin();

            int length = up - pos;
            if(length>1){
                return nums[pos];
            }

            pos = up;

        }

        assert(false);
        
    }


};

int main(){
    Solution s;

    {
        vector<int> input = {1,3,4,2,2};
        assert(s.findDuplicate(input) == 2);
    }


}
