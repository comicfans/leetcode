#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    static constexpr int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int best = 0;
        for(int y =0; y<matrix.size();++y){
            for(int x = 0; x < matrix[0].size();++x){

                // it must be first

                bool okAsHead = true;
                for(int i = 0;i<4;++i){

                    int ty = y + offset[i][0];
                    int tx = x + offset[i][1];

                    if(tx <0 || tx >= matrix[0].size() || ty < 0 || ty >= matrix.size()){
                        continue;
                    }


                    if(matrix[ty][tx] < matrix[y][x]){
                        okAsHead = false;
                        break;
                    }
                }

                if(!okAsHead){
                    continue;
                }

                int thisLength = search(matrix, y,x);
                best = max(best, thisLength);
            }
        }

        return best;
        
    }

    int search(const vector<vector<int>>& matrix, int y, int x){

        int prevValue = matrix[y][x];


        int subBest = 0;

        for(int i =0;i< 4;++i){

            int ty = y +offset[i][0];
            int tx = x + offset[i][1];

            if(tx <0 || tx >= matrix[0].size() || ty < 0 || ty >= matrix.size()){
                continue;
            }

            if(matrix[ty][tx]<= matrix[y][x]){
                continue;
            }

            int subLength = search(matrix, ty,tx);
            subBest = max(subBest, subLength);
        }

        return 1 + subBest;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> mat = {{0},{1},{5},{5}};
        s.longestIncreasingPath(mat);
    }
    {
        vector<vector<int>> mat = {{9,9,4},{6,6,8},{2,1,1}};
        assert(s.longestIncreasingPath(mat) == 4);
    }
}
