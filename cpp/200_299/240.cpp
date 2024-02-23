#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.front().front()> target|| matrix.back().back() < target){
            return false;
        }

        for(auto& row:matrix){
            if(binary_search(row.begin(),row.end(),target)){
                return true;
            }
        }
        
        return false;
        
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> matrix = {{1,2,3,4,5},
                                      {6,7,8,9,10},
                                      {11,12,13,14,15},
                                      {16,17,18,19,20},
                                      {21,22,23,24,25}};
        assert(s.searchMatrix(matrix,19));
    }
    {
        vector<vector<int>> matrix = {{1,4,7,11,15},
                                      {2,5,8,12,19},
                                      {3,6,9,16,22},
                                      {10,13,14,17,24},
                                      {18,21,23,26,30}};
        assert(s.searchMatrix(matrix,5));
    }
}
