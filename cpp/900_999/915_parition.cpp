#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {

        vector<pair<int,int>> leftMaxRightMin;
        leftMaxRightMin.resize(nums.size());

        leftMaxRightMin[0].first = nums[0];
        for(int i = 1;i<nums.size();++i){
            leftMaxRightMin[i].first = max(leftMaxRightMin[i-1].first, nums[i]);
        }

        leftMaxRightMin.back().second = nums.back();
        for(int i = nums.size()-2;i>=0;--i){
            leftMaxRightMin[i].second=min(nums[i],leftMaxRightMin[i+1].second);
        }

        for(int idx = 0;idx < nums.size()-1; ++idx){
            if(leftMaxRightMin[idx].first <= leftMaxRightMin[idx+1].second){
                return idx + 1;
            }
        }

        return -1;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {1,1};
        assert(s.partitionDisjoint(nums) == 1);
    }

    {
        vector<int> nums = {1,1,1,0,6,12};
        assert(s.partitionDisjoint(nums) == 4);
    }
}
