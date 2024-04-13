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

        for(int y = 0; y< mat.size(); ++y){
            for(int x = 0; x< mat[y].size(); ++x){

                if(mat[y][x]== 0){
                    ret[y][x] = 0;
                    rec(mat, ret, y, x, 1);
                }
            }
        }


        return ret;
        
    }

    void rec(const vector<vector<int>>& mat,vector<vector<int>>& ret, int y, int x, int dis){

        
        const int offset[][2] ={{0,1},{0,-1},{1,0},{-1,0}};

        for(int i = 0; i< 4;++i){
            int newY = y + offset[i][0];
            int newX = x + offset[i][1];
            if(newX <0 || newX >= mat[0].size() || newY <0 || newY >= mat.size()){
                continue;
            }

            if(mat[newY][newX] == 0){
                continue;
            }

            if(ret[newY][newX] <= dis ){
                continue;
            }

            ret[newY][newX] = dis;

            rec(mat,ret, newY, newX, dis+1);
        }
    }
};
