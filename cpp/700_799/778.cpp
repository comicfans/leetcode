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
    int swimInWater(vector<vector<int>>& grid) {
        
        int time = 0;

        vector<vector<int>> reach = grid;
        for(auto& v:reach){
            fill(v.begin(),v.end(),numeric_limits<int>::max());
        }

        vector<pair<int,int>> newNodes={{0,0}};

        int currentTime = 0;
        while(!newNodes.empty()){

            vector<pair<int,int>> next;
            for(auto p : newNodes){
                int res = recWalk(grid,reach,next, p.first,p.second, currentTime);
                if(res != -1){
                    return res;
                }
            }
            //find lowest value which more than currentTime;
            //
            int newTime = numeric_limits<int>::max();
            for(auto p: next){
                if(grid[p.first][p.second]<= currentTime){
                    continue;
                }
                newTime = min(grid[p.first][p.second],newTime);
            }


            currentTime = newTime;
            
            swap(newNodes,next);
        }


        return -1;
    }
    int recWalk(const vector<vector<int>>& grid,vector<vector<int>>& reach, vector<pair<int,int>>& newNodes, int y,int x, int currentTime){

        if(reach[y][x]!= numeric_limits<int>::max()){
            return -1;
        }

        if( y == grid.size()-1 && x == grid[0].size()-1){
            return currentTime;
        }

        if(grid[y][x] > currentTime){
            newNodes.push_back({y,x});
            return -1;
        }

        reach[y][x] = currentTime;

        int yxOff[][2] ={{-1,0},{1,0},{0,1},{0,-1}};

        for(auto off: yxOff){

            int tryY = y + off[0];
            int tryX = x + off[1];

            if(tryY <0 || tryY >= reach.size() || tryX <0 || tryX >= reach[0].size()){
                continue;
            }

            int thisHeight = max(grid[y][x],currentTime);

            if(thisHeight < grid[tryY][tryX]){
                newNodes.push_back({tryY,tryX});
                continue;
            }


            int sub = recWalk(grid,reach,newNodes, tryY,tryX, currentTime);
            if(sub != -1){
                return sub;
            }
        }

        return -1;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> input = {{0,2},{1,3}};
        assert(s.swimInWater(input) == 3);
    }
    {
        vector<vector<int>> input = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
        assert(s.swimInWater(input) == 16);
    }
}
