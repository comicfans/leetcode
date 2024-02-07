#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        vector<vector<int>> maxLength(matrix.size(),vector<int>(matrix[0].size()));

        for(int y = 0; y<matrix.size();++y){
            int prev = 0;
            for(int x = matrix[y].size()-1; x>=0; --x){
                if(matrix[y][x] == '0'){
                    prev = 0;
                    continue;
                }

                maxLength[y][x] = prev + 1;

                prev = maxLength[y][x];
            }
        }

        int maxSide = 0;
        for(int y =0; y< matrix.size();++y){
            for(int x = 0; x<matrix[y].size();++x){


                int verticalMinLength = maxLength[y][x];
                int i=1;
                for(;i<verticalMinLength && y+i < matrix.size() &&  verticalMinLength > maxSide; ++i){
                    verticalMinLength = min(verticalMinLength, maxLength[y+i][x]);
                }

                maxSide = max(maxSide,min(i,verticalMinLength));

            }
        }

        return maxSide * maxSide;
        
    }
};

int main(){
    Solution s;
    {
        vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        assert(s.maximalSquare(matrix) == 4);
    }
}
