#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        vector<vector<int>> result = grid;

        for(auto & v: result){
            fill(v.begin(),v.end(),0);
        }

        recWalk(grid,result, k, 0,0);

        return result[0][0];
    }

    void recWalk(const vector<vector<int>>&grid, )
};
