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
    int minimumVisitedCells(vector<vector<int>>& grid) {

        vector<vector<int>> reach = grid;
        for(auto& v: reach){
            fill(v.begin(),v.end(),-1);
        }
        reach[0][0]= 1;
        set<pair<int,int>> newNodes= {{0,0}};

        if((grid.size()==1)&&(grid[0].size()==1)){
            return 1;
        }

        vector<int> perRowMax(grid.size());
        vector<int> perColMax(grid[0].size());

        while(!newNodes.empty()){

            set<pair<int,int>> next;
            for(auto p: newNodes){
                auto y = p.first;
                auto x = p.second;
                auto value = grid[y][x];
                auto existing = reach[y][x];

                int xMax = min<int>(value + x,grid[0].size()-1);

                int xMin = x+1;//max(perRowMax[y]+1,x+1);
                //perRowMax[y] = max(xMax,perRowMax[y]);
                for(int newX= xMin; newX<=xMax; ++newX){
                    if(newX == grid[0].size()-1 && y == grid.size()-1){
                        return existing+1;
                    }
                    if(reach[y][newX] == -1){
                        reach[y][newX] = existing+1;
                        next.insert({y,newX});
                    }
                }

                int yMax=min<int>(value+y,grid.size()-1);;
                int yMin = y+1;//max(y+1, perColMax[x]);
                //perColMax[x] = max(perColMax[x], yMin);
                for(int newY = yMin;newY <= yMax; ++newY){
                    if(x== grid[0].size()-1 && newY == grid.size()-1){
                        return existing+1;
                    }
                    if(reach[newY][x]==-1){
                        reach[newY][x] = existing+1;
                        next.insert({newY,x});
                    }
                }
            }
            next.swap(newNodes);
        }
        
        return -1;
        
    }

};

#include "parse.h"
int main(){
    Solution s;
    {
        vector<vector<int>> grid = {{1, 3, 1, 3, 3, 2}, {1, 1, 0, 3, 2, 2}, {1, 3, 2, 0, 0, 3}, {0, 2, 1, 0, 3, 1}, {2, 0, 2, 0, 3, 0}, {3, 0, 0, 2, 3, 0}, {3, 2, 1, 2, 0, 0}};
        int expect = 8;
        assert(s.minimumVisitedCells(grid) == expect);
    }
    {
        vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
        int expect = 4;
        assert(s.minimumVisitedCells(grid) == expect);
    }
    {
        auto grid = pvvi("2617_case.txt",0);
        s.minimumVisitedCells(grid);
    }
}
