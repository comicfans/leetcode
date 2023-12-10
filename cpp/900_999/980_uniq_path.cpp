#include <vector>
#include <set>
#include <cassert>


using namespace std;
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        //find start point

        int startx=-1,starty=-1;
        int expectStep = 0;
        for(int x = 0; x< grid.size(); ++ x){
            for(int y = 0; y < grid[x].size(); ++ y){

                if(grid[x][y]==1){
                    startx = x;
                    starty = y;
                }else if(grid[x][y] == 0){
                    ++expectStep;
                }
            }
        }

        return recSearch(grid, startx, starty, 0,expectStep);
    }

    int recSearch(vector<vector<int>>& grid,int lastx, int lasty, const int currentFill, const int expectStep){

        int subways = 0;

        int tryDir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        for(int i =0 ;i<4;++i){

            int tryx = lastx + tryDir[i][0];
            if(tryx <0 || tryx >= grid.size()){
                continue;
            }

            int tryy = lasty + tryDir[i][1];
            if(tryy <0 || tryy >= grid[tryx].size()){
                continue;
            }

            if(grid[tryx][tryy] == 0){
                grid[tryx][tryy] = -1;
                int thisSubway = recSearch(grid,tryx,tryy,currentFill+1,expectStep);
                subways+= thisSubway;
                grid[tryx][tryy] = 0;
            }else if (grid[tryx][tryy] == 2){
                if (currentFill == expectStep){
                    ++subways;
                }
            }
        }

        return subways;
    }
};

int main(int , char**){

    Solution s;
    {
        vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
        assert(s.uniquePathsIII(grid) == 4);
    }
    {
        vector<vector<int>> grid = {{0,1},{2,0}};
        assert(s.uniquePathsIII(grid) == 0);
    }
}
