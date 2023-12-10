#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        int width = matrix[0].size();
        for(int y = 1;y<matrix.size();++y){
            for(int x = 0;x < width ;++x){
                if(matrix[y][x]==1){
                    matrix[y][x] = matrix[y-1][x] + matrix[y][x];
                }
            }
        }

        int best = 0;
        for(int y = 0;y< matrix.size();++y){
            auto& row = matrix[y];
            sort(row.begin(),row.end());

            for(int beginPos = 0; beginPos < width;){

                int thisRes = row[beginPos] * (width - beginPos);
                best = max(best, thisRes);

                beginPos = lower_bound(row.begin()+ beginPos + 1, row.end(), row[beginPos]+1) - row.begin();
            }
        }
        
        return best;
    }
};

int main(){
    Solution s;
    {
       vector<vector<int> >matrix = {{1,1,1,0,1,1,1,0},
                                     {1,1,1,1,1,1,1,1},
                                     {1,0,1,1,1,1,1,1},
                                     {1,0,1,0,0,0,1,1},
                                     {0,1,1,0,1,1,1,1},
                                     {1,1,0,1,1,1,0,1},
                                     {1,1,1,1,1,1,0,0},
                                     {1,1,1,1,1,1,1,0},
                                     {1,1,1,1,0,1,0,1},
                                     {1,0,0,1,1,1,1,1},
                                     {1,1,1,0,1,1,1,1},
                                     {1,1,1,1,1,0,1,1},
                                     {1,0,1,0,0,0,0,0},
                                     {0,0,1,1,1,0,1,1},
                                     {1,1,0,1,1,1,0,1}};

        assert(s.largestSubmatrix(matrix) == 16);
    }
    {
        vector<vector<int> >matrix = {{0,0,1},{1,1,1},{1,0,1}};
        assert(s.largestSubmatrix(matrix) == 4);
    }
    
}
