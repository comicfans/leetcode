#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i= 0;i<board.size();++i){

            map<char,int> rowAppear;
            map<char,int> columnAppear;
            for(int j = 0; j< board[0].size();++j){

                char v= board[i][j];
                if(v != '.'){
                    if(rowAppear.count(v)){
                        return false;
                    }

                    rowAppear[v]++;
                }


                v= board[j][i];
                if(v == '.'){
                    continue;
                }
                if(columnAppear.count(v)){
                    return false;
                }
                columnAppear[v]++;
            }
        }

        for(int gy = 0;gy<3;++gy){
            for(int gx = 0; gx < 3;++gx){

                map<char,int> appear;
                for(int y = 0;y<3;++y){
                    for(int x = 0;x < 3;++x){

                        int globalY = gy * 3+ y;
                        int globalX = gx * 3 + x;
                        char v= board[globalY][globalX];
                        if(v == '.'){
                            continue;
                        }
                        if(appear.count(v)){
                            return false;
                        }
                        appear[v]++;
                    }
                }

            }
        }

        
        return true;
    }
};
