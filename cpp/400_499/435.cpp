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

        int prevEnd = numeric_limits<int>::min();

        vector<int> cache(intervals.size(), numeric_limits<int>::max());

        return recRemove(intervals,0, numeric_limits<int>::min(),cache);
    }

    int recRemove(const vector<vector<int>>& intervals,int currentPos, int prevEnd,
                   vector<int>& cache){

        if(currentPos == intervals.size()){
            return 0;
        }

        
        if(intervals[currentPos][0] >= prevEnd){
            if(cache[currentPos]!= numeric_limits<int>::max()){
                return cache[currentPos];
            }
        }

        int keepThisRes = recRemove(intervals, currentPos + 1,intervals[currentPos][1],cache);

        cache[currentPos] = keepThisRes;

        if((currentPos != intervals.size()-1) && (intervals[currentPos][1]> intervals[currentPos+1][0])){
            int removeThisRes = 1+ recRemove(intervals, currentPos + 1, numeric_limits<int>::min(),cache);
            cache[currentPos] = min(cache[currentPos], keepThisRes);
        }


        if(intervals[currentPos][0]>= prevEnd){
            //can use this element
            return cache[currentPos];
        }

        //try next without this one
        int removeThisAndFollow = 1+recRemove(intervals, currentPos + 1, prevEnd, cache) ;

        return removeThisAndFollow;
    }
};

#include "../parse.h"

int main(){
    Solution s;
    {
        vector<vector<int>> input = {{-3035,30075},{1937,6906},{11834,20971},{44578,45600},{28565,37578},{19621,34415},{32985,36313},{-8144,1080},{-15279,21851},{-27140,-14703},{-12098,16264},{-36057,-16287},{47939,48626},{-15129,-5773},{10508,46685},{-35323,-26257}};
        assert(s.eraseOverlapIntervals(input) == 9);
    }
    {
         vector<vector<int>> input = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
        assert(s.eraseOverlapIntervals(input) == 7);
    }
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
    {
        auto input = pvvi("435_case.txt",0);
        s.eraseOverlapIntervals(input);
    }
    
}
