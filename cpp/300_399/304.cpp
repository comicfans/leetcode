#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix){
        swap(copy,matrix);

        for(int y = 0; y < copy.size(); ++y){
            auto& row = copy[y];
            for(int x = 1; x < row.size();++x){
                row[x] = row[x-1] + row[x];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int res = 0;
        for(int row = row1;row<=row2;++row){
            int rowSum = copy[row][col2] - (col1==0?0:copy[row][col1-1]);
            res += rowSum;

        }
        return res;
    }

private:
    vector<vector<int>> copy;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
