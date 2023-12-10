#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        if(mat == target){
            return true;
        }

        float center = (mat.size()-1)/2.0;
        for(int i = 0; i< 3;i ++){

            float cosV = cos((i+1) * M_PI/ 2);
            float sinV = sin((i+1) * M_PI /2);

            vector<vector<int>> once = mat;

            for(int y=0;y<mat.size();++y){
                for(int x=0;x<mat.size();++x){

                    float xPolar = x - center;
                    float yPolar = y - center;

                    int xFinal =  round(xPolar * cosV  - yPolar * sinV + center);
                    int yFinal = round(xPolar * sinV + yPolar * cosV + center);

                    once[yFinal][xFinal] = mat[y][x];
                }
            }

            if(once == target){
                return true;
            }
        }

        return false;

        
    }
};

int main(){
    Solution s;
    
    {
        vector<vector<int>> mat = {{0,1},{1,0}};
        vector<vector<int>> target = {{1,0},{0,1}};
        auto res = s.findRotation(mat,target);
        assert(res);

    }
    {
        vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
        vector<vector<int>> target = {{1,1,1},{0,1,0},{0,0,0}};
        auto res = s.findRotation(mat,target);
        assert(res);


    }
}
