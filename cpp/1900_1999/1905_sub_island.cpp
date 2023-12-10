#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:


    bool recWalk(const vector<vector<int>>& grid1, const vector<vector<int>>& grid2,
                 int y, int x, set<pair<int,int>>& walked){

        bool oneFalse = false;
        if(grid1[y][x] == 0){
            oneFalse = true;
        }

        walked.insert({y,x});

        int yxOffset[][2] = {{0,1},{0,-1},{-1,0},{1,0}};

        for(auto thisOffset: yxOffset){
            int newY = thisOffset[0] + y;
            int newX = thisOffset[1] + x;

            
            

            if(newY>=0 && newY < grid1.size() && newX >=0 && newX < grid1[newY].size()){
                if(walked.count({newY,newX})){
                    continue;
                }

                if(grid2[newY][newX] == 0){
                    continue;
                }

                bool subOk = recWalk(grid1,grid2,newY,newX,walked);
                if(!subOk){
                    oneFalse = true;
                }
            }
        }

        return !oneFalse;
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        set<pair<int,int>> walked;
        int ret = 0;
        for(int y = 0;y < grid1.size(); ++y){
            for(int x = 0;x< grid1[y].size();++x){

                if(grid2[y][x]==0){
                    continue;
                }

                if(walked.count({y,x})){
                    continue;
                }

                if(y == 9 && x== 0){
                    int a = 3;
                }

                bool thisIs = recWalk(grid1,grid2, y,x, walked);

                ret += thisIs;
            }
        }

        return ret;  
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}}; 
        vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
        assert(s.countSubIslands(grid1,grid2) == 3);
    }
    {

        vector<vector<int>> grid1 = {{1,1,1,1,0,0},{1,1,0,1,0,0},{1,0,0,1,1,1},{1,1,1,0,0,1},{1,1,1,1,1,0},{1,0,1,0,1,0},{0,1,1,1,0,1},{1,0,0,0,1,1},{1,0,0,0,1,0},{1,1,1,1,1,0}};

        vector<vector<int>> grid2 = {{1,1,1,1,0,1},{0,0,1,0,1,0},{1,1,1,1,1,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{0,1,1,1,1,1},{1,1,0,1,1,1},{1,0,0,1,0,1},{1,1,1,1,1,1},{1,0,0,1,0,0}};
        assert(s.countSubIslands(grid1,grid2) == 0);
    }
}

