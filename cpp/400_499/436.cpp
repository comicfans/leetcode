#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        for(int i = 0;i<intervals.size(); ++i){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(),intervals.end());

        vector<int> ret(intervals.size());
        vector<int> toSearch(3, -INT_MAX);
        for(int i = 0;i< intervals.size(); ++i){

            const auto& p = intervals[i];
            toSearch[0] = p[1];

            auto pos = lower_bound(intervals.begin()+i, intervals.end(), toSearch);

            if(pos  == intervals.end()){
                ret[p[2]] = -1;
                continue;
            }

            ret[p[2]] = (*pos)[2];


        }

        return ret;

        
    }
};
