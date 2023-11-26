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

        vector<vector<int>> columns;
        vector<int> temp;
        temp.resize(matrix.size());
        for(int i=0;i<matrix[0].size();++i){
            columns.push_back(temp);
            for(int y = 0;y<matrix.size();++y){
                columns[i][y] = matrix[y][i];
            }
        }

        set<pair<int,int>> cache;

        int best = 0;
        for(int cIdx = 0; cIdx < columns.size(); ++ cIdx){

            auto& col = columns[cIdx];

            auto onePos = find(col.begin(),col.end(),1);

            while(onePos != col.end()){


                auto beginIdx = onePos - col.begin();
                auto nextZeroPos = find(onePos + 1, col.end(),0);
                int nextZeroIdx = nextZeroPos - col.begin();



                for(int i = beginIdx;i < nextZeroIdx;++i){
                    for(int j = nextZeroIdx; j> i;--j){
                        if(cache.count({i, j})){
                            continue;
                        }

                        int width = j- i;
                        int height = 0;

                        for(int check = 0; check < columns.size();++check){
                            if(equal(columns[check].begin() + i, columns[check].begin() + j, col.begin()+i)){
                                ++height;
                            }
                        }

                        int thisArea = width * height;

                        best = max(thisArea, best);
                        cache.insert({i, j});
                    }
                }


                

                if(nextZeroPos == col.end()){
                    break;
                }

                onePos = find(col.begin() + nextZeroIdx  + 1,col.end(),1);
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
