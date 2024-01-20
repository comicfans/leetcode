#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> all;

        int m = grid.size();
        int n = grid[0].size();


        for(int i = 0;i< m; ++i){
            all.push_back(vector<int>(n,-1));
        }


        return recWalk(grid,all,0,0);
        
    }

    int recWalk(const vector<vector<int>>& obstacleGrid,vector<vector<int>>& all,int y,int x){
        if(y >= all.size() || x >= all[y].size()){
            return -1;
        }

        if(all[y][x]!=-1){
            return all[y][x];
        }

        if(y== all.size()-1 && x== all[0].size()-1){
            return obstacleGrid[y][x];
        }
        

        //walk right
        int walkRight = recWalk(obstacleGrid,all, y,x+1);
        int walkDown = recWalk(obstacleGrid,all, y+1, x);

        int minStep = numeric_limits<int>::max();
        if(walkRight >= 0){
            minStep = walkRight;
        }
        if(walkDown >= 0){
            minStep = min(minStep, walkDown);
        }

        int total = minStep+obstacleGrid[y][x];


        all[y][x] =  total;
        return total;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> obs = {{1,3,1},{1,5,1},{4,2,1}};
        assert(s.minPathSum(obs) == 7);
    }
}
