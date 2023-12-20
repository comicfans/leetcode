#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int repeatN = nums.size()/2;

        int segment = repeatN / 2;

        set<int> ret;

        for(int i = 0; i< nums.size(); i+= segment){

            int thisV = nums[i];
            if(ret.count(thisV)){
                return thisV;
            }

            ret.insert(thisV);

        }
        
        assert(false);
    }
};
