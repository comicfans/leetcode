#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {

        vector<int> nums;

        while(n>0){
            nums.push_back(n%10);
            n/=10;
        }

        auto backup = nums;
        next_permutation(nums.rbegin(),nums.rend());
        if(!lexicographical_compare(backup.rbegin(),backup.rend(),nums.rbegin(),nums.rend())){
            return -1;
        }

        uint64_t value = 0;
        uint64_t mul = 1;
        for(auto d: nums){
            value += d* mul;
            mul *= 10;
        }

        uint64_t max_i = (uint64_t)numeric_limits<int32_t>::max();
        if(value > max_i){
            return -1;
        }
        return value;
        
    }
};

int main(){
    Solution s;
    {

        auto v = s.nextGreaterElement(1999999999);
        assert(v==-1);
    }
    {
        auto v = s.nextGreaterElement(230241);
        assert(v==230412);
    }
    {
        auto v = s.nextGreaterElement(12);
        assert(v == 21);
    }
    {
        auto v = s.nextGreaterElement(21);
        assert(v == -1);
    }
    {
        auto v = s.nextGreaterElement(1);
        assert(v == -1);
    }
    {
        auto v = s.nextGreaterElement(2147483486);
        assert(v == -1);
    }
}
