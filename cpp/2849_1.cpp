#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int xDelta = abs(sx - fx);
        int yDelta = abs(sy - fy);

        int minTime = max(xDelta, yDelta);
        if(minTime == 0){
            return t== 0;
        }

        return t>=minTime;
        
    }
};
