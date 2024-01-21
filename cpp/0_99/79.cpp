#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int y = 0;y <board.size();++y ){
            for(int x = 0; x<board[0].size();++x){

                if(board[y][x] != word.front()){
                    continue;
                }


                board[y][x] = ' ';
                if(canFind(board,y,x,word,1)){
                    return true;
                }
                board[y][x] = word.front();

            }
        }

        return false;
        
    }

    bool canFind(vector<vector<char>>& board, int y, int x, const string& word, int idx){

        if(idx == word.size()){
            return true;
        }

        int offset[][2]= {{0,1},{0,-1},{-1,0},{1,0}};

        for(int dir = 0; dir < 4; ++dir){

            int newY = y + offset[dir][0];
            int newX = x + offset[dir][1];

            if(newY<0 || newX <0 || newY >= board.size() || newX >=board[0].size()){
                continue;
            }

            if(board[newY][newX] != word[idx]){
                continue;
            }

            board[newY][newX] = ' ';
            if(canFind(board,newY,newX, word,idx+1)){
                return true;
            }
            board[newY][newX] = word[idx];
        }

        return false;
    }
};
