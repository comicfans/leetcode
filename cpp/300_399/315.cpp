#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        vector<pair<int,int>> valueIdx;
        for(int i =0;i<nums.size();++i){
            valueIdx.push_back({nums[i],i});
        }

        sort(valueIdx.begin(),valueIdx.end());

        vector<int> ret (nums.size());

        for(int i =0;i<nums.size();++i){

            int thisValue = nums[i];
            auto ub = upper_bound(valueIdx.begin(),valueIdx.end(),pair<int,int>{thisValue-1, nums.size()});
            auto ubIdx =  ub - valueIdx.begin();
            for(auto it = 0; it < ubIdx;++it){
                if(valueIdx[it].second > i){
                    ++ret[i];
                }
            }
        }

        return ret;
        
    }
};
