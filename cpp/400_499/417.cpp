#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#ifdef LEETCODE
#include "../parse.h"
#endif

using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> cache(heights.size(), vector<int>(heights.front().size(),0));

        set<pair<int,int>> path;
        for(int y = 0;y< heights.size(); ++y){
            for(int x = 0;x < heights[y].size();++x){
                rec(heights, y,x,cache,path);
            }
        }


        //0 not tried,  1, to pac, 2 to atl , 3 too both, 4 none
vector<vector<int>> ret;
        for(int y = 0; y < cache.size();++y){
            for(int x = 0; x< cache[y].size(); ++x){
                if(cache[y][x] == 3){
                    ret.push_back({y,x});
                }
            }
        }

        return ret;
        
    }

    int rec(const vector<vector<int>>& heights, int y, int x, vector<vector<int>>& cache, set<pair<int,int>>& path){

        if(cache[y][x]!= 0){
            return cache[y][x];
        }

        int offset[][2]= {{0,1},{0,-1},{1,0},{-1,0}};

        assert(path.count({y,x}) == 0);
        auto pos =path.insert({y,x});

        bool reachPac = false;
        bool reachAtl= false;
        bool hasUnknown = false;
        for(int dir = 0; dir < 4 && (!( reachPac&& reachAtl));++dir){
            int newY = y + offset[dir][0];
            int newX = x + offset[dir][1];

            if(newY < 0 || newX < 0 ){
                reachPac = true;
                continue;
            }

            if(newY >= heights.size() || newX >= heights[0].size()){
                reachAtl = true;
                continue;
            }
            
            if(heights[newY][newX] > heights[y][x]){
                continue;
            }

            if(path.count({newY,newX})){
                hasUnknown = true;
                continue;
            }

            int subRes = rec(heights, newY, newX, cache,path);

            switch(subRes){
                case 0:{
                    assert(false);
                }
                case 1:{
                    reachPac = true;
                    continue;
                }
                case 2:{
                    reachAtl = true;
                    continue;
                }
                case 3:{
                    reachPac = true;
                    reachAtl = true;
                    break;
                }
                case 4:{
                    continue;
                }
            }

            if(reachAtl && reachPac){
                break;
            }
        }

        path.erase(pos.first);

        int thisRes = 0;
        if(reachAtl && reachPac){
             thisRes = 3;
        }else if(reachPac){
            thisRes = 1;
        }else if (reachAtl){
            thisRes = 2;
        }else{
            thisRes = 4;
        }

        if(!hasUnknown){
            cache[y][x] = thisRes;
        }

        return thisRes;
    }
};

int main(){
    Solution s;
    {
        VVI heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
        VVI expect = {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};
        auto res = s.pacificAtlantic(heights);
        assert(res == expect);
    }
    {

        VVI heights = {{1,1},{1,1}};
        VVI expect = {{0,0},{0,1},{1,0},{1,1}};
        auto res = s.pacificAtlantic(heights);
        assert(res == expect);

    }
    
    {
        VVI heights = {{1,2,2,3,5},
                       {3,2,3,4,4},
                       {2,4,5,3,1},
                       {6,7,1,4,5},
                       {5,1,1,2,4}};

        VVI expect = {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};
        auto res = s.pacificAtlantic(heights);
        assert(res == expect);

    }
    {
        VVI heights = {{1}};
        VVI expect = {{0,0}};
        auto res = s.pacificAtlantic(heights);
        assert(res == expect);
    }
    
}
