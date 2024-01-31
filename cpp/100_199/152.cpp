#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {



        int res = nums.front();
        for(int i =0;i<nums.size(); ++i){
            int thisStart = nums[i];
            res = max(res,thisStart);

            for(int j = i+1; j <nums.size(); ++j){
                thisStart *= nums[j];

                res = max(thisStart,res);
            }
        }
        return res;

        
    }
};
