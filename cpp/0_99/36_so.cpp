#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {


        map<int, set<char>> rowRule;
        map<int, set<char>> columnRule;
        map<pair<int,int>,set<char>> subRule;

        set<char> allDigits ={'1','2','3','4','5','6','7','8','9'};
        for(int i =0; i< board.size(); ++i){
            rowRule[i] = allDigits;
            columnRule[i]=allDigits;

            int gy = i /3;
            int gx = i % 3;

            subRule[{gy,gx}] = allDigits;
        }




        for(int y = 0;y < board.size();++y){
            for(int x= 0;x < board[0].size(); ++x){
                char v = board[y][x];
                if(v == '.'){
                    continue;
                }

                rowRule[y].erase(v);
                columnRule[x].erase(v);

                int gy = y / 3;
                int gx = x / 3;

                subRule[{gy,gx}].erase(v);
            }
        }

        recFind(board, rowRule, columnRule, subRule, 0,0);
        
    }
    bool recFind(vector<vector<char>>& board,
                 map<int, set<char>>& rowRule,
                 map<int, set<char>>& columnRule,
                 map<pair<int,int>,set<char>>& subRule,
                 int y,int x){

        if(board[y][x] != '.'){
            //already filled
            // try next pos

            bool tryNext = false;
            for(int nextY = y;nextY < 9; ++nextY){
                for(int nextX = 0; nextX < 9 ;++nextX){

                    if((nextY == y)&&(nextX<=x)){
                        continue;
                    }
                    tryNext = true;

                    return recFind(board,rowRule,columnRule,subRule,nextY,nextX);
                }
            }

            //all tried success
            return true;
        }

        auto& rowPossible = rowRule[y];
        auto& columnPossible = columnRule[x];

        int gy = y/3;
        int gx = x/3;
        auto& subPossible = subRule[{gy,gx}];

        vector<char> intersect1;
        set_intersection(rowPossible.begin(),rowPossible.end(),
                         columnPossible.begin(),columnPossible.end(),
                         back_inserter(intersect1));

        vector<char> trySet;
        set_intersection(intersect1.begin(),intersect1.end(),
                         subPossible.begin(),subPossible.end(),
                         back_inserter(trySet));

        for(char v: trySet){
            board[y][x] = v;
            rowPossible.erase(v);
            columnPossible.erase(v);
            subPossible.erase(v);

            if(recFind(board,rowRule,columnRule,subRule,y,x)){
                return true;
            }
            //revert
            board[y][x] = '.';
            rowPossible.insert(v);
            columnPossible.insert(v);
            subPossible.insert(v);
        }

        return false;
    }
};

int main(){
    Solution s;

    {
        vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};


        s.solveSudoku(board);

        vector<vector<char>> expect = {{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};

        assert(board == expect);

    }
}
