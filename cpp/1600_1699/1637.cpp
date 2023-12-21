#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        if(points.empty()){
            return 0;
        }

        sort(points.begin(),points.end(),[](auto& lhs, auto& rhs){
            return lhs[0] < rhs[0];
        });

        int prevX = points.front()[0];

        auto nextPos = upper_bound(points.begin(),points.end(),vector<int>{prevX,prevX},[](auto& lhs, auto& rhs){
            return lhs[0] < rhs[0];
        }) - points.begin();

        int maxWidth = 0;
        while(nextPos != points.size()){

            auto thisX = points[nextPos][0];
            int thisWidth = thisX - prevX;

            maxWidth = max(maxWidth, thisWidth);

            prevX = thisX;
            nextPos = upper_bound(points.begin(),points.end(),vector<int>{prevX,prevX},[](auto& lhs, auto& rhs){
            return lhs[0] < rhs[0];
        }) - points.begin();

        }


        return maxWidth;
        
    }
};
