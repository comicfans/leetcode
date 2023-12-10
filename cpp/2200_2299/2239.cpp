#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int current = numeric_limits<int>::min();

        for(auto n:nums){
            if(labs(n) < labs(current)){
                current = n;
            }else if(labs(n) == labs(current)){
                if(n > current){
                    current = n;
                }
            }
        }

        
        return current;
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {-4,-2,1,4,8};
        s.findClosestNumber(nums);
    }
}
