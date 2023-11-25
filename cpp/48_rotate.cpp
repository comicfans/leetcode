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
    void rotate(vector<vector<int>>& matrix) {


        float cosV[3];
        float sinV[3];
        for(int i = 0;i<3;++i){
            cosV[i] = cos(M_PI / 2 * (i+1));
            sinV[i] = sin(M_PI/ 2 * (i+1));
        }


        float center = (matrix.size() - 1) / 2.0;
        auto rotate = [&](int y,int x){
        float xPolar = x - center;
                float yPolar = y - center;

                int xTarget[4];
                int yTarget[4];

                for(int i =0;i< 3; ++ i){

                    xTarget[i] =  round(xPolar * cosV[i]  - yPolar * sinV[i] + center);
                    yTarget[i] = round(xPolar * sinV[i] + yPolar * cosV[i] + center);
                }

                xTarget[3] = x;
                yTarget[3] = y;

                int temp = matrix[y][x];
                for(int i = 0;i<3;++i){
                    matrix[yTarget[3-i]][xTarget[3-i]] = matrix[yTarget[3-i-1]][xTarget[3-i-1]];
                }
                matrix[yTarget[0]][xTarget[0]] = temp;
        };


        for(int y=0;y<matrix.size()/2;++y){
            for(int x=0;x<matrix.size()/2;++x){
                rotate(y,x);
            }
        }

        for(int x = matrix.size()/2;x < (matrix.size()+1)/2;++x){
            for(int y = 0; y < matrix.size()/2;++y){
                rotate(y,x);
            }
        }

        
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};
        s.rotate(matrix);
    }
}
