#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        int height = matrix.size();
        for(int i =0;i< height; ++i){

            int ele = matrix[i][0];

            int limit = min(matrix.size() - i, matrix[0].size());
            for(int j = 1; j < limit;++j){

                if(matrix[i+j][j] != ele){
                    return false;
                }

            }
        }
        int width = matrix[0].size();

        for(int i = 1;i<width;++i){
            int ele = matrix[0][i];

            int limit = min(matrix[0].size() - i, matrix.size());
            for(int j = 1; j < limit;++j){
                if(matrix[j][i+j] != ele){
                    return false;
                }
            }
        }
        

        return true;
    }
};

int main(){

    Solution s;
    {
        vector<vector<int>> matrix = {{11,74,0,93},
                                      {40,11,74,7}};
        assert(!s.isToeplitzMatrix(matrix));
    }
    {
        vector<vector<int>> matrix = {{11,40},
                                      {74,11},
                                      {0,74},
                                      {93,7}};
        assert(!s.isToeplitzMatrix(matrix));
    }
    {
        vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
        assert(s.isToeplitzMatrix(matrix));
    }
    
}
