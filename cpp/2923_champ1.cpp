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
    int findChampion(vector<vector<int>>& grid) {
        int total = grid.size();

        for (int i=0;i<grid.size();++i){

            auto sum = accumulate(grid[i].begin(),grid[i].end(), 0);

            if(sum== total - 1){
                return i;
            }

        }

        return -1;
        
    }
};
