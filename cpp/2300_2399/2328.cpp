#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {


        vector<vector<int>> result = grid;
        for(auto& v: result){
            fill(v.begin(),v.end(),-1);
        }

        recFill(grid,result);
        
        return grid[0][0]
    }

    void recFill(const vector<vector<int>>& grid, vector<vector<int>>& result){
    }
};
