#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int offset[][2] ={{0,1},{0,-1},{1,0},{-1,0}};
        int ret = 0;
        for(int y = 0;y<grid.size(); ++y){
            for(int x= 0 ;x<grid[y].size(); ++x){

                if(grid[y][x]==0){
                    continue;
                }

                for(int i = 0;i<4;++i){

                    int newY = y + offset[i][0];
                    int newX = x + offset[i][1];

                    if(newX <0 || newY <0 || newX >= grid[y].size() || newY >= grid.size()){
                        ++ret;
                        continue;
                    }

                    if(grid[newY][newX] == 0){
                        ++ret;
                    }

                }



            }
        }
        
        return ret;
    }
};
