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

                if(board[y][x] == 'X'){
                    rec(board,y,x);
                    ++ret;
                }

            }
        }
        return ret;
    }

    void rec(vector<vector<char>>& board, int y,int x){


        for(int newY = y+1; newY < board.size() && board[newY][x] == 'X'; ++newY){
            board[newY][x] = '.';
        }

        for(int newX = x+1; newX < board[y].size() && board[y][newX] == 'X'; ++newX){
            board[y][newX] = '.';
        }

        board[y][x] = '.';

    }
};
