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

        vector<bool> rows(m);
        vector<bool> cols(n);

        for(auto& v: indices){
            rows[v[0]]= !rows[v[0]];
            cols[v[1]]=!cols[v[1]];
        }

        int rowNumber = accumulate(rows.begin(),rows.end(),0);
        int colNumber = accumulate(cols.begin(),cols.end(),0);

        int oddRows = n* rowNumber;
        int oddCols = m * colNumber;
        int dup = rowNumber * colNumber;

        return oddRows + oddCols - dup*2;
        
    }
};

int main(){
    Solution s;
    {
    }

}
