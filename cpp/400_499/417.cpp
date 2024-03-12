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

        vector<vector<pair<bool,bool>>> cache(heights.size(), vector<pair<bool,bool>>(heights.front().size()));

        for(int y = 0; y< heights.size();++y){
            cache[y].front().first = true;
            cache[y].back().second = true;
        }

        for(int x = 0; x< heights[0].size(); ++x){
            cache.front()[x].first = true;
            cache.back()[x].second  = true;
        }

        //0 not tried,  1, to pac, 2 to atl , 3 too both, 4 none
        for(int y = 0; y < cache.size();++y){
            for(int x = 0; x< cache[y].size(); ++x){
                rec(heights, cache, y,x);
            }
        }
        vector<vector<int>> ret;
        for(int y = 0; y < cache.size();++y){
            for(int x = 0; x< cache[y].size(); ++x){
                if(cache[y][x] == pair<bool,bool>{true, true}){
                    ret.push_back({y,x});
                }
            }
        }
        return ret;
        
    }

    void rec(const vector<vector<int>>& heights, vector<vector<pair<bool,bool>>>& cache, int y,int x){

        if(cache[y][x] == pair<bool,bool>{false,false}){
            return;
        }

        int offset[][2]= {{0,1},{0,-1},{1,0},{-1,0}};
        for(int dir = 0; dir < 4 ;++dir){
            int newY = y + offset[dir][0];
            int newX = x + offset[dir][1];

            

            if(newY < 0 || newX < 0 || newY >= heights.size() || newX >= heights[0].size()){
                continue;
            }

            if(heights[newY][newX] < heights[y][x]){
                continue;
            }

            bool targetFirst = cache[newY][newX].first ;
            bool targetSecond = cache[newY][newX].second;

            cache[newY][newX].first |= cache[y][x].first;
            cache[newY][newX].second |= cache[y][x].second;


            if(targetFirst != cache[newY][newX].first || targetSecond != cache[newY][newX].second){
                rec(heights, cache, newY, newX);
            }
        }
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
