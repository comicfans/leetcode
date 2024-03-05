#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> valueCount;

        for(auto v:nums){
            ++valueCount[v];
        }
        vector<pair<int,int>> res(valueCount.begin(),valueCount.end());

        sort(res.begin(),res.end(),[](const auto& lhs, const auto& rhs){
            return lhs.second > rhs.second;
        });


        vector<int> ret;
        transform(res.begin(),res.begin()+k, back_inserter(ret),[](auto pair){
            return pair.first;
        });

        return ret;

        
    }
};
