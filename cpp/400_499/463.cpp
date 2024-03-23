#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#ifdef LEETCODE
    #include "../parse.h"
#endif

using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int ret = 0;
        for(int y = 0;y<grid.size(); ++y){
            for(int x= 0 ;x<grid[y].size(); ++x){

                if(grid[y][x]==0){
                    continue;
                }

                if(y == 0){
                    ++ret;
                }else if(grid[y-1][x] == 0){
                    ++ret;
                }

                if(y == grid.size()-1){
                    ++ret;
                }else if(grid[y+1][x] == 0){
                    ++ret;
                }


                if(x == 0){
                    ++ret;
                }else if(grid[y][x-1] == 0){
                    ++ret;
                }

                if(x == grid[y].size()-1){
                    ++ret;
                } else if(grid[y][x+1]==0){
                    ++ret;
                }
            }
        }
        
        return ret;
    }


};

int main(){
    Solution s;
    {
        VVI grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
        int expect = 16;
        auto res = s.islandPerimeter(grid);
        assert(res == expect);
    }
}
