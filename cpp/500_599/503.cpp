#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> ret(nums.size());

        int currentMax = numeric_limits<int>::min();
        
        map<int,set<int>> valueIdx;

        for(int idx = 0; idx < nums.size(); ++idx){
            int v = nums[idx];

            auto p = valueIdx.lower_bound(v);

            for(auto it = valueIdx.begin(); it!= p; ){
                for(auto r: it->second){
                    ret[r] = v;
                }
                auto temp = it;
                ++it;
                valueIdx.erase(temp);
            }

            valueIdx[v].insert(idx);
        }

        if(!valueIdx.empty()){

            for(int c = 0; c < nums.size(); ++c){

                int v = nums[c];

                auto p = valueIdx.lower_bound(v);
                for(auto it = valueIdx.begin(); it!= p; ){
                    for(auto r: it->second){
                        ret[r] = v;
                    }
                    auto temp = it;
                    ++it;
                    valueIdx.erase(temp);
                }
            }

            for(const auto& [key,value]: valueIdx){
                for(auto i: value){
                    ret[i] = -1;
                }
            }

        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {1,2,3,4,3};
        vector<int> expect = {2,3,4,-1,4};
        auto res = s.nextGreaterElements(input);
        assert(expect == res);

    }

    {
        vector<int> input = {1,2,1};
        vector<int> expect = {2,-1,2};
        auto res = s.nextGreaterElements(input);
        assert(expect == res);
    }

}
