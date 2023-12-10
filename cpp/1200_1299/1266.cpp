#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int ret = 0;

        for(int i = 1;i<points.size();++i){

            auto& prev  = points[i-1];
            auto& current = points[i];

            int xDelta = abs(prev[0] - current[0]);
            int yDelta = abs(prev[1] - current[1]);



            ret += max(xDelta,yDelta) ;
        }
        
        return ret;
    }
};
