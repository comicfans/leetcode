#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        vector<vector<int>> res(dungeon.size(), vector<int>(dungeon.front().size(),0));

        res.back().back() = max(1, 1- dungeon.back().back());

        for(int y = dungeon.size()-1; y>=0; --y){
            for(int x = dungeon[y].size()-1;x>=0;--x){

                if(x == dungeon[y].size()-1){
                    if(y != dungeon.size()-1){
                        int thisMinFromDown =  res[y+1][x] - dungeon[y][x];
                        thisMinFromDown = max(1,thisMinFromDown);
                        res[y][x] = thisMinFromDown;
                    }
                    continue;
                }


                int minRes = res[y][x+1] - dungeon[y][x] ;
                minRes = max(1,minRes);

                if(y!= dungeon.size()-1){
                    int thisMinFromDown =  res[y+1][x] - dungeon[y][x];
                    thisMinFromDown = max(1,thisMinFromDown);
                    minRes = min(minRes, thisMinFromDown);
                }


                res[y][x] = minRes;

            }
        }

        return max(1, res[0][0]);
        
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> dungeon = {{-3,5}};
        assert(s.calculateMinimumHP(dungeon) == 4);
    }
    {
        vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};

        assert(s.calculateMinimumHP(dungeon) == 7);

    }
}
