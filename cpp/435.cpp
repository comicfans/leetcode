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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {


        sort(intervals.begin(),intervals.end());

        int best = numeric_limits<int>::max();
        int prevEnd = numeric_limits<int>::min();
        recRemove(intervals,1,intervals[0][1] ,0,best);
        return best;
    }

    void recRemove(const vector<vector<int>>& intervals,int currentPos, int prevEnd, int currentRemoved, int& best){

        if(currentRemoved == best){
            return;
        }

        for(int i = currentPos; i < intervals.size(); ++i){
            const auto &current  = intervals[i];

            if(current[0] >= prevEnd){
                prevEnd = current[1];
                continue;
            }
            

            //has overlap, stop here
            //two option, remove prev, or remove current
            {
                //remove current

                recRemove(intervals,i + 1, prevEnd,currentRemoved+1,best);
            }
            {
                //remove prev
                recRemove(intervals, i + 1, current[1],currentRemoved+1,best);
            }

            return;
        }
        //walked to confirm no overlap

        best = min(best,currentRemoved);
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> input = {{1,2},{2,3},{3,4},{1,3}};
        assert(s.eraseOverlapIntervals(input) == 1);
    }
    {
        vector<vector<int>> input = {{1,2},{1,2},{1,2}};
        assert(s.eraseOverlapIntervals(input) == 2);
    }
    {
        vector<vector<int>> input = {{0,2},{1,3},{2,4},{3,5},{4,6}};
        assert(s.eraseOverlapIntervals(input) == 2);
    }
}
