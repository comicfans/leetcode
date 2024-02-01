#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int ret = 0;

        for(int y = 0;y<grid.size(); ++y){
            for(int x = 0;x<grid[y].size();++x){

                if(grid[y][x] == '1'){
                    ++ret;
                    recFill(grid,y,x);
                }
            }
        }

        return ret;
        
    }
    void recFill(vector<vector<char>>& grid, int y ,int x){

        grid[y][x] = 'f';

        int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        for(int i = 0;i<4;++i){

            int newY = y + offset[i][0];
            int newX = x + offset[i][1];

            if(newY == grid.size() || newY < 0 || newX <0 || newX== grid[y].size() || grid[newY][newX]!='1'){
                continue;
            }

            recFill(grid,newY,newX);
        }
    }
};
