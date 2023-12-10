#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        next_permutation(nums.begin(),nums.end());
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {3,2,1};
        vector<int> expect = {1,2,3};
        s.nextPermutation(input);
        assert(input == expect);
    }
}
