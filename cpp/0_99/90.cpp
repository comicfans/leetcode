#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> sret;
        int maxV = 1<<nums.size();
        for(int bit=0;bit < maxV; ++bit){
            vector<int> thisSet;
            int b = 0;
            int copy = bit;
            while(copy>0){
                if(copy%2 == 1){
                    thisSet.push_back(nums[b]);
                }
                ++b;
                copy/=2;
            }
            sort(thisSet.begin(),thisSet.end());
            sret.insert(thisSet);
        }

        vector<vector<int>> ret(sret.begin(),sret.end());

        return ret;
        
    }
};

