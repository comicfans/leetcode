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

        map<pair<int,int>,int> cache;
        int best = numeric_limits<int>::max();


        auto res = recFind(grid,0,0,cache, best,0);
        return res == numeric_limits<int>::max()?-1:res+1;
        
    }

    int recFind(const vector<vector<int>>& grid,const int x,const int y,
                map<pair<int,int>,int>& cache, int& best,const int step){


        if(x == grid[0].size()-1 && y == grid.size()-1){
            best = min(best, step);
            return 0;
        }

        if(grid[y][x] == 0){
            return numeric_limits<int>::max();
        }

        //if(step >= best){
        //    return numeric_limits<int>::max();
        //}

        auto cachePos = cache.find({y,x});
        if(cachePos != cache.end()){
            return cachePos->second;
        }

        //try right
        int thisBest = numeric_limits<int>::max();
        for(int newX= x+1; newX<= min<int>(grid[y][x] + x,grid[0].size()-1);++newX){
            int subBest = recFind(grid,newX, y, cache,best, step+1);
            if(subBest != numeric_limits<int>::max()){
                thisBest= min(subBest+1,thisBest);
            }
        }

        for(int newY = y +1;newY <= min<int>(grid[y][x]+y,grid.size()-1); ++ newY){
            int subBest = recFind(grid,x,newY, cache,best, step+1);
            if(subBest != numeric_limits<int>::max()){
                thisBest = min(subBest+1,thisBest);
            }
        }

        cache[{y,x}]=thisBest;

        return thisBest;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
        int expect = 4;
        assert(s.minimumVisitedCells(grid) == expect);
    }
}
