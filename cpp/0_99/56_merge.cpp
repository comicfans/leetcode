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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ret={intervals.front()};

        for(int i = 1;i<intervals.size();){
            //try to merge prev and this
            //
            vector<int> searchValue = {ret.back()[1],numeric_limits<int>::max()};

            auto lower = lower_bound(intervals.begin() + i,intervals.end(), searchValue, [](auto lhs,auto rhs){
                return lhs[0] < rhs[0];
            });

            if(lower == intervals.end()){
                --lower;
            }else{

            auto eq = (*lower)[0]== searchValue[0];

            if(!eq){
                if(lower == intervals.begin() + i) {
                    ret.push_back(intervals[i]);
                    ++i;
                    continue;
                }
                --lower;
            }
            }




            int mergeNumber = lower - intervals.begin() - i +1;


            //merge up to endpos - 1
            ret.back()[1] = max((*lower)[1],ret.back()[1]);
            i += mergeNumber;
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> ranges = {{1,4},{1,4}};
        auto res = s.merge(ranges);
        vector<vector<int>> expect = {{1,4}};
        assert(res == expect);

    }
    {
        vector<vector<int>> ranges = {{1,4},{4,5}};
        auto res = s.merge(ranges);
        vector<vector<int>> expect = {{1,5}};
        assert(res == expect);
    }
    {
        vector<vector<int>> ranges = {{1,3},{2,6},{8,10},{15,18}};
        auto res = s.merge(ranges);
        vector<vector<int>> expect = {{1,6},{8,10},{15,18}};
        assert(res == expect);
    }
    
}
