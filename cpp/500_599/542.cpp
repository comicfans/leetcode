#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        vector<vector<int>> ret(mat.size(),vector<int>(mat.front().size(),INT_MAX));
        vector<pair<int,int>> inner;

        for(int y = 0; y< mat.size(); ++y){
            for(int x = 0; x< mat[y].size(); ++x){
                if(mat[y][x] == 0){
                    inner.push_back({y,x});
                    ret[y][x] = 0;
                }
            }
        }

        const int offset[][2] ={{0,1},{0,-1},{1,0},{-1,0}};
        int dis = 1;
        while(!inner.empty()){

            vector<pair<int,int>> outer;

            for(auto p: inner){

                for(int i = 0;i<4;++i){

                    int newY = p.first + offset[i][0];
                    int newX = p.second + offset[i][1];
                    if(newX <0 || newX >= mat[0].size() || newY <0 || newY >= mat.size()){
                        continue;
                    }

                    if(ret[newY][newX]!= INT_MAX){
                        continue;
                    }
                    outer.push_back({newY,newX});
                    ret[newY][newX] = dis;
                }

            }

            ++dis;
            outer.swap(inner);
        }

        return ret;
    }

    
};
