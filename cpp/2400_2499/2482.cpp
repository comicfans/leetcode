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
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {



        vector<int> rowSums (grid.size());
        vector<int> colSums (grid[0].size());

            int width = grid[0].size();
            int height = grid.size();
        for(int row = 0; row <height; ++row){
            for(int col = 0;col < width;++col){

                int v = grid[row][col];
                rowSums[row] += v;
                colSums[col] += v;
            }
        }

        vector<vector<int>> ret = grid;
        for(int row = 0; row <height; ++row){
            for(int col = 0;col < width;++col){

                ret[row][col] = rowSums[row] + colSums[col] - (width - rowSums[row]) - (height - colSums[col]);
            }
        }


        return ret;


        
    }
};
