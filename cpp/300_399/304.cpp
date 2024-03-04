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
        swap(_copy,matrix);

        for(int y = 0; y < _copy.size(); ++y){
            auto& row = _copy[y];
            for(int x = 0; x < row.size();++x){
                row[x] = (x>0?row[x-1]:0) + (y >0? _copy[y-1][x]:0) + row[x] - (y>0&& x>0? _copy[y-1][x-1]:0);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int bottomRight = _copy[row2][col2];
        int left = (col1>0 ?_copy[row2][col1-1]:0);
        int top = (row1>0 ? _copy[row1-1][col2]:0);

        int topLeft = (col1>0 && row1 >0? _copy[row1-1][col1-1]:0);

        return bottomRight - left - top + topLeft;
        
    }

private:
    vector<vector<int>> _copy;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
