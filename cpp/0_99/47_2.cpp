#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> ret = {nums};

        while(next_permutation(nums.begin(),nums.end())){
            ret.push_back(nums);
        }

        return ret;
    }
};
