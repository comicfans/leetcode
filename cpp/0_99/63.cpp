#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<int>> all;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }

        for(int i = 0;i< m; ++i){
            all.push_back(vector<int>(n));
        }

        all[m-1][n-1] = 1;

        return recWalk(obstacleGrid,all,0,0);
        
    }

    int recWalk(const vector<vector<int>>& obstacleGrid,vector<vector<int>>& all,int y,int x){
        if(y >= all.size() || x >= all[y].size()){
            return 0;
        }

        if(all[y][x]!=0){
            return all[y][x];
        }

        if(obstacleGrid[y][x]== 1){
            return 0;
        }

        //walk right
        int walkRight = recWalk(obstacleGrid,all, y,x+1);
        int walkDown = recWalk(obstacleGrid,all, y+1, x);

        int total = walkRight+walkDown;

        all[y][x] = total;
        return total;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> obs = {{0,0,0},{0,1,0},{0,0,0}};
        assert(s.uniquePathsWithObstacles(obs) == 2);
    }
}
