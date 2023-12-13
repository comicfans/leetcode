#include <cmath>
#include <cstdint>
#include <iostream>
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
    int minFlips(vector<vector<int>>& mat) {

        uint16_t bits = 0;

        // mat width height <= 3
        // every step is a bit xor 
        
        vector<uint16_t> yxOp;
        yxOp.reserve(mat.size() * mat[0].size());


        for(int y = 0;y < mat.size(); ++y){
            for(int x =0;x < mat[y].size();++x){

                int bitOp = 0;

                for(int xOff : {-1,0,1}){
                    for(int yOff: {-1,0,1}){

                        if(abs(xOff) ==1 && abs(yOff) == 1){
                            continue;
                        }

                        int nx = x+xOff;
                        int ny = y+yOff;

                        if(nx<0 || nx >= mat[0].size() || ny <0 || ny>= mat.size()){
                            continue;
                        }

                        int shift = ny*mat[0].size() + nx;
                        bitOp = bitOp | (1<<shift);
                    }
                }

                yxOp.push_back(bitOp);
            }
        }

        uint16_t state = 0;
        for(int y =0;y<mat.size();++y){
            for(int x = 0;x < mat[0].size();++x){
                if(mat[y][x]){

                    if((y>1 && y < mat.size()-2) || (x > 1 && x < mat[0].size()-2)){
                        return false;
                    }


                    int shift = y * mat[0].size() + x;
                    state = state | (1 << shift);
                }
            }
        }

        vector<int> steps(pow(2,mat.size() * mat[0].size()), numeric_limits<int>::max());

        vector<uint16_t> path = {state};
        auto res = recFind(path, steps, yxOp, -1);

        return res;

    }

    int recFind(vector<uint16_t>& path,vector<int>& steps , const vector<uint16_t>& yxOp, int lastTry){

        if(path.back()== 0){
            return 0;
        }

        if(steps[path.back()]!= numeric_limits<int>::max()){
            return steps[path.back()];
        }


        int bestLater = numeric_limits<int>::max();
        for(int tryNumber = (lastTry == -1?0:1); tryNumber < yxOp.size();++tryNumber){
            int thisTry = (lastTry + 1 + tryNumber) % yxOp.size();

            if((path.back() | yxOp[thisTry]) == 0){
                continue;
            }


            uint16_t newState = path.back() xor yxOp[thisTry];
            if(find(path.begin(),path.end(),newState)!= path.end()){
                //already reached 
                continue;
            }

            path.push_back(newState);
            int laterStep = recFind(path,steps, yxOp, thisTry);
            path.pop_back();

            if(laterStep != -1){
                bestLater = min(bestLater, laterStep);
            }
        }



        if(bestLater == numeric_limits<int>::max()){
            steps[path.back()] = -1;
        }else{
            steps[path.back()] = bestLater + 1;
        }
        
        return steps[path.back()];
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> mat = {{0},{1},{1}};
        assert(s.minFlips(mat)==1);
    }
    {
        vector<vector<int>> mat = {{0}};
        assert(s.minFlips(mat) == 0);

    }   
    
    {
        vector<vector<int>> mat = {{1,0,0},{1,0,0}};
        assert(s.minFlips(mat) == -1);
    }
    {
        vector<vector<int>> mat = {{0,0},{0,1}};
        assert(s.minFlips(mat) == 3);
    }
    {
        vector<vector<int>> mat = {{1,1,1},{1,0,1},{0,0,0}};
        assert(s.minFlips(mat)==6);
    }

}
