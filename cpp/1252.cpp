#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {

        int rows[m];
        fill_n(rows,m,0);
        int cols[n];
        fill_n(cols,n,0);

        for(auto& v: indices){
            rows[v[0]]= 1-rows[v[0]];
            cols[v[1]]=1-cols[v[1]];
        }

        int rowNumber = accumulate(rows,rows+m,0);
        int colNumber = accumulate(cols,cols+n,0);

        int oddRows = n* rowNumber;
        int oddCols = m * colNumber;
        int dup = rowNumber * colNumber;

        return oddRows + oddCols - dup*2;
        
    }
};
