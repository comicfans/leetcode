#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ret;

        int total = pow(2, nums.size());

        for(int i =0 ;i< total; ++i){

            vector<int> thisOne;

            int pos = 0;

            int copy = i;
            while(copy > 0){
                if(copy%2 == 1){
                    thisOne.push_back(nums[pos]);
                }
                ++pos;
                copy /= 2;
            }

            ret.push_back(thisOne);

        }
        return ret;
    }
};
