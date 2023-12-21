#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {

        int best = 0;

        vector<vector<int>> cache = grid;
        for(auto& v:cache){
            fill(v.begin(),v.end(),-1);
        }

        for(int y = 0;y < grid.size();++y){

            int thisBest = recFind(grid, cache, 0, y);
            best = max(best,thisBest);

        }

        return best;
    }

    int recFind(const vector<vector<int>>& grid, vector<vector<int>>& cache,int x, int y){


        if(cache[y][x] != -1){
            return cache[y][x];
        }


        int offsetXY[][2] = {{1,-1},{1,0},{1,1}};

        int thisBest = 0;
        for(int i = 0;i <3;++i){

            int newX = x + offsetXY[i][0];
            int newY = y + offsetXY[i][1];

            if(newX <0 || newX >= grid[0].size() || newY <0 ||newY >=grid.size()){
                continue;
            }

            if(grid[newY][newX]<= grid[y][x]){
                continue;
            }

            int thisStep = 1;
            int subStep = recFind(grid,cache, newX,newY);


            thisBest = max(thisStep+subStep, thisBest);
        }

        cache[y][x] = thisBest;

        return thisBest;

    }
};
