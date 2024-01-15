#include <vector>
#include <sstream>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        

        sort(nums.begin(),nums.end(),[](auto& lhs,auto& rhs){

            if(lhs.size() > rhs.size()){
                return false;
            }

            if(lhs.size() < rhs.size()){
                return true;
            }

            for(int i = 0; i<lhs.size();++i){
                if(lhs[i]<rhs[i]){
                    return true;
                }
                if(lhs[i]> rhs[i]){
                    return false;
                }
            }

            return false;
        });

        return nums[nums.size() - k];

    }
};
