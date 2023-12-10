#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> yxOffset = {{0,1},{1,0},{0,-1},{-1,0}};

        int current = 0;

        int y = 0;
        int x = 0;
        vector<int> ret={matrix[y][x]};
        matrix[0][0] = numeric_limits<int>::min();
        int total = matrix.size() * matrix[0].size();

        while(ret.size() < total){


            int newY = y+ yxOffset[current].first;
            int newX = x+ yxOffset[current].second;

            if((newY<0 ) || (newY>= matrix.size()) || (newX <0) || (newX >= matrix[0].size())){
                current = (current + 1) % 4;
                continue;
            }

            if(matrix[newY][newX]== numeric_limits<int>::min()){
                current = (current + 1) % 4;
                continue;
            }

            ret.push_back(matrix[newY][newX]);
            matrix[newY][newX] = numeric_limits<int>::min();


            y = newY;
            x = newX;
        }

        return ret;

    }
};


int main(){

    Solution s;
    {
        vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
        vector<int> expect =  {1,2,3,6,9,8,7,4,5};
        assert(s.spiralOrder(matrix) == expect);
    }
    {
        vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        vector<int> expect = {1,2,3,4,8,12,11,10,9,5,6,7};
        assert(s.spiralOrder(matrix) == expect);
    }
}
