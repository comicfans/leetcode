#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int ret = 0;
        for(int y = 0; y< board.size(); ++y){
            for(int x = 0; x< board[y].size(); ++x){

                if(board[y][x] == '.'){
                    continue;
                }

                if(y >0 && board[y-1][x] == 'X'){
                    continue;
                }

                if(x >0 && board[y][x-1] == 'X'){
                    continue;
                }

                ++ret;

            }
        }
        return ret;
    }

    
};
