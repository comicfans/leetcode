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

        vector<int> toSearch ;
        toSearch.push_back(target);
        auto pos = lower_bound(matrix.begin(),matrix.end(), toSearch,[](const auto&lhs, const auto& rhs){
            return lhs.front() < rhs.front();
        });

        auto y = pos - matrix.begin();

        if(y != matrix.size()){

            if(matrix[y].front() == target){
                return true;
            }
        }

        if(y == 0){
            return false;
        }

        --y;

        return binary_search(matrix[y].begin(),matrix[y].end(),target);
        
    }
};

