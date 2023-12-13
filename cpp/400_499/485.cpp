#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int current  = 0;
        for(auto v: nums){
            if(v){
                ++current;
            }else{
                ret = max(ret,current);
                current = 0;
            }
        }
        return max(current,ret);
    }
};
