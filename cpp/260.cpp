#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<int> res;

        bool oneFound = false;
        bool twoFound = false;

        auto pos = 0;

        while(pos < nums.size()){

            auto range = equal_range(nums.begin(),nums.end(), nums[pos]);

            if(range.second - range.first == 1){
                oneFound = true;
                res.push_back(nums[pos]);
            }else if(range.second - range.first == 1){
                twoFound = true;
                res.push_back(nums[pos]);
            }

            if(oneFound && twoFound){
                return res;
            }

            pos = (range.second - nums.begin());

        }
        
        return res;
    }
};
