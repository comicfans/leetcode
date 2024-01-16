#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {

        sort(points.begin(),points.end(),[](auto& lhs,auto& rhs){
            return lhs[0] < rhs[0];
        });

        vector<int> ret;
        ret.reserve(queries.size());


        for(const auto& circle: queries){

            //x,y,r
            //

            //AABB
            int xmin = circle[0] - circle[2];
            int xmax = circle[0] + circle[2];

            int ymin = circle[1] - circle[2];
            int ymax = circle[1] + circle[2];

            auto beginPos = lower_bound(points.begin(),points.end(),vector<int>{xmin}, [](auto& lhs, auto& rhs){
                return lhs[0]< rhs[0];
            });

            auto endPos = upper_bound(points.begin(),points.end(),vector<int>{xmax}, [](auto& lhs, auto& rhs){
                return lhs[0]< rhs[0];
            });

            int rPow = circle[2] * circle[2];
            int res  = 0;
            for(auto it = beginPos; it!= endPos; ++ it){

                if((*it)[1]<ymin || (*it)[1] > ymax){
                    continue;
                }

                double xPow = ((*it)[0] - circle[0])*((*it)[0] - circle[0]);
                double yPow = ((*it)[1] - circle[1])*((*it)[1] - circle[1]);
                double disPow = xPow + yPow;


                if(disPow <= rPow){
                    ++res;
                }
            }

            ret.push_back(res);
        }
        
        return ret;
    }
};
