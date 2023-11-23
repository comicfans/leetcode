#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    int minAbs(const map<int,int>& values){

        if(values.size()==1){
            return values.begin()->second == 1?abs(values.begin()->second):-1;
        }

        vector<int> keyOnly;
        for(auto kv: values ){
            keyOnly.push_back(kv.first);
        }


        int minAbs= keyOnly[1] - keyOnly[0];
        for(int i = 1;i<keyOnly.size();++i){
            minAbs = min(minAbs, keyOnly [i] - keyOnly[i-1]);
        }


        return minAbs;
    }
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> ret;
        ret.resize(queries.size());

        for(int i=0;i<queries.size();++i){

            int begin = queries[i][0];
            int end = queries[i][1];

            map<int,int> sub;
            for(int i = begin;i<=end;++i){
                sub[nums[i]]++;
            }
            ret[i] = minAbs(sub);
        }

        return ret;
        
    }
};

int main(){

    Solution s;
    {
        vector<int> nums = {1,3,4,8};
        vector<vector<int>> queries = {{0,1},{1,2},{2,3},{0,3}};
        vector<int> expect = {2,1,4,1};

        auto res = s.minDifference(nums,queries);
        assert(res == expect);
    }

}
