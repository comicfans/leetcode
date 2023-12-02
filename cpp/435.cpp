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

        set<int> removed;
        int best = numeric_limits<int>::max();
        recRemove(intervals,1,removed,best);
        return best;
    }

    void recRemove(const vector<vector<int>>& intervals,int currentPos, set<int>& removed, int& best){

        if(removed.size() == best){
            return;
        }

        for(int i = currentPos; i < intervals.size(); ++i){
            const auto &current  = intervals[i];

            int prev = i - 1;
            while((prev>=0) && (removed.count(prev) != 0)){
                --prev;
            }

            if(prev < 0){
                continue;
            }

            auto prevRange = intervals[prev];
            if(prevRange[1]<=current[0]){
                continue;
            }

            //has overlap, stop here
            //two option, remove prev, or remove current
            {
                //remove current

                auto insertPos = removed.insert(i);
                recRemove(intervals,i + 1, removed,best);
                removed.erase(insertPos.first);
            }
            {
                //remove prev
                auto insertPos = removed.insert(prev);
                recRemove(intervals, i + 1, removed,best);
                removed.erase(insertPos.first);
            }

            return;
        }
        //walked to confirm no overlap

        best = min<int>(best,removed.size());
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
}
