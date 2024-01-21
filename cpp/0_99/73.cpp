#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<int> row(matrix[0].size());
        for(int y = 0; y< matrix.size(); ++y){
            bool fillRow = false;
            for(int x = 0; x< matrix[y].size(); ++x){
                if(matrix[y][x] == 0){
                    row[x] = 1;
                    fillRow = true;
                }
            }
            if(fillRow){
                fill(matrix[y].begin(),matrix[y].end(),0);
            }
        }

        for(int x = 0; x<row.size(); ++x){
            if(row[x]==0){
                continue;
            }
            for(int y = 0;y<matrix.size();++y){
                matrix[y][x] = 0;
            }
        }
        
    }
};

