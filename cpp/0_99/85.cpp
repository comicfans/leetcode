#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        const int width = matrix.front().size();
        const int height = matrix.size();
        vector<vector<int>> maxWidth(height,vector<int>(width));


        for(int i= 0;i<height;++i){
            for(int j = 0 ;j<width;++j){
                if(matrix[i][width-1-j]=='0'){
                    continue;
                }
                maxWidth[i][width -1 - j] = (matrix[i][width-1-j]=='1') + (j == 0?0:maxWidth[i][width-j]);
            }
        }


        int maxArea = 0;
        for(int i=0;i<height;++i){
            for(int j = 0;j<width;++j){
                if(maxWidth[i][j] ==0){
                    continue;
                }

                int thisHeight = 1;
                int minWidth = maxWidth[i][j];
                maxArea = max(maxArea, minWidth);
                for(;i+thisHeight< height && maxWidth[i+thisHeight][j]; ++thisHeight){
                    minWidth = min(minWidth, maxWidth[i+thisHeight][j]);
                    maxArea = max(maxArea, (thisHeight+1) * minWidth);
                }
            }
        }

        return maxArea;
        
    }
};

int main(){

    Solution s;
    {
        vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        assert(s.maximalRectangle(matrix) ==6);
    }
}
