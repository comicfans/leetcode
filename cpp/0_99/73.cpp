#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {



        int firstRow = 1;

        for(int y = 0; y < matrix.size(); ++y){
            for(int x = 0; x < matrix[y].size(); ++x){
                if(matrix[y][x]!=0){
                    continue;
                }

                matrix[0][x] = 0;

                if(y != 0){
                    matrix[y][0] = 0;
                }else{
                    firstRow = 0;
                }
            }
        }


        for(int y = 1; y < matrix.size(); ++y){
            if(matrix[y][0] == 0){
                fill(matrix[y].begin(),matrix[y].end(),0);
            }
        }

        for(int x = 0; x <matrix[0].size(); ++x){
            if(matrix[0][x] == 0){
                for(int y = 0;y < matrix.size(); ++y){
                    matrix[y][x] = 0;
                }
            }
        }

        if(firstRow == 0){
            fill(matrix[0].begin(),matrix[0].end(),0);
        }
    }
};


int main(){
    Solution s;
    {
        vector<vector<int>> matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
        vector<vector<int>> expect = {{0,0,3,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

        s.setZeroes(matrix);
        assert(matrix == expect);
    }
}

