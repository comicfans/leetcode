#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int big = abs(k) / mat[0].size();

        k = ((big + 1) * mat[0].size() - k) % mat[0].size();

        for(int y = 0;y< mat.size();++y){

            int offset = (y%2==0? k : -k);
            
            for(int x = 0;x < mat[y].size(); ++x){

                int target = (x + offset + mat[y].size())   % mat[y].size();
                if(mat[y][x] != mat[y][target]){
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
        vector<vector<int>>  matrix = {{9,1,8,9,2,9,1,8,9,2},{10,2,7,8,9,10,2,7,8,9},{7,6,6,9,5,7,6,6,9,5}};

        assert(s.areSimilar(matrix, 5));
    }
    {
        vector<vector<int>> matrix={{9,10,10,6,6,8,10,7,10,9},{10,6,1,10,10,5,7,9,9,2},{8,5,8,3,5,2,2,9,7,10}};
        assert(s.areSimilar(matrix,20));
    }
}
