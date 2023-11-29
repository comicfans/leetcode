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
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int res = 0;
        for(int row = row1;row<=row2;++row){
            res += accumulate(copy[row].begin()+col1,copy[row].begin()+col2+1,0);

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
