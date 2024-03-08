#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        sort(rectangles.begin(),rectangles.end());

        long xmin = INT_MAX, ymin = INT_MAX, xmax = 0, ymax = 0;
        long areaSum = 0;
        for(const auto& r: rectangles){
            xmin = min(xmin, (long)r[0]);
            ymin = min(ymin, (long)r[1]);
            xmax = max(xmax, (long)r[2]);
            ymax = max(ymax, (long)r[3]);
            long areaThis = ((long)r[2] - (long)r[0]) * ((long)r[3] - (long)r[1]);
            areaSum+=areaThis;
        }

        long areaTotal = (ymax - ymin) * (xmax - xmin);

        if(areaTotal != areaSum){
            return false;
        }

        //check no overlap
        for(int i = 0; i< rectangles.size(); ++i){
            
            int xRight = rectangles[i][2];

            auto searchEnd = upper_bound(rectangles.begin() + i + 1, rectangles.end(), vector<int>{xRight - 1,INT_MAX,INT_MAX,INT_MAX}) - rectangles.begin();

            for(int j = i+1; j< searchEnd; ++j){
                bool yoverlap = (min(rectangles[j][3],  rectangles[i][3]) - max(rectangles[j][1], rectangles[i][1]) > 0);
                if(yoverlap){
                    return false;
                }

            }
        }


        return true;
    }
};

int main(){

    Solution s;
    {
        vector<vector<int>> rectangles ={{0,0,2,2},{1,1,3,3},{2,0,3,1},{0,3,3,4}};
        assert(!s.isRectangleCover(rectangles));
    }
    {
vector<vector<int>> rectangles ={{0,0,4,1},{7,0,8,2},{6,2,8,3},{5,1,6,3},{4,0,5,1},{6,0,7,2},{4,2,5,3},{2,1,4,3},{0,1,2,2},{0,2,2,3},{4,1,5,2},{5,0,6,1}};
        assert(s.isRectangleCover(rectangles));
    }
    {
        vector<vector<int>> rectangles = {{0,0,1,1},{0,1,3,2},{1,0,2,2}};
        assert(!s.isRectangleCover(rectangles));
    }
}
