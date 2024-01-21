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
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int prev = numeric_limits<int>::max();
        int sameCount = 1;
        int skip = 0;
        for(int i = 0; i< size;){
            nums[i] = nums[i+skip];
            if(nums[i]!=prev){                
                sameCount = 1;
                prev = nums[i];
                ++i;
                continue;
            }
            ++sameCount;
            if(sameCount==3){
                ++skip;
                --sameCount;
                --size;
            }else{
                ++i;
            }
        } 
        return nums.size()-skip;   
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {0,0,1,1,1,1,2,3,3};
        vector<int> expect= {0,0,1,1,2,3,3,3,3};
        assert(s.removeDuplicates(input) == 7);

        assert(input == expect);
    }
    {
        vector<int> input = {1,1,1,2,2,3};
        vector<int> expect= {1,1,2,2,3,3};
        assert(s.removeDuplicates(input) == 5);

        assert(input == expect);
    }
    
}
