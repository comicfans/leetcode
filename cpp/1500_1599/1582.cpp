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
    int numSpecial(vector<vector<int>>& mat) {

        int ret = 0;
        for(int y = 0;y<mat.size();++y){
            
            int pos = -1;
            for(int x = 0;x<mat[y].size();++x){
                if(mat[y][x]){
                    if(pos == -1){
                        pos = x;
                    }else{
                        pos = -1;
                        break;
                    }
                }

            }
                if(pos == -1){
                    continue;
                }

                bool foundY = false;
                for(int checkY = 0;checkY<mat.size();++checkY){
                    if(mat[checkY][pos]){
                        if(foundY){
                            foundY = false;
                            break;
                        }else{
                            foundY = true;
                        }
                    }
                }

                ret+= foundY;
                

        }

        return ret;

    }

};

int main(){
    Solution s;
    {
        vector<vector<int>> mat = {{0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,1,0,0,0},{1,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,1,0,0,0,1}};
        assert(s.numSpecial(mat) == 0);
    }
    {
        vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};

        assert(s.numSpecial(mat) == 1);
    }
    {
        vector<vector<int>> mat =  {{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,1},{0,0,0,0,1,0,0,0},{1,0,0,0,1,0,0,0},{0,0,1,1,0,0,0,0}};
        assert(s.numSpecial(mat) == 1);
    }
    
}
