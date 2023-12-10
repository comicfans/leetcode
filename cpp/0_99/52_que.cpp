#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        

        int ret = 0;
        vector<string> grid;

        string empty;
        empty.resize(n,'.');
        for(int i = 0;i< n;++i){
            grid.push_back(empty);
        }
        
        recFind(ret, grid,0);

        return ret;
    }

    void recFind(int& ret,vector<string>& existing, int searchIdx){

        if(searchIdx == existing.size()){
            ++ret;
            return;
        }


        for(int i = 0; i < existing.size();++i){
            //try to put it at 
            //y = searchIdx,
            //x = i;
            //search conflict at x
            bool reject = false;
            for(int check = 0;check < searchIdx;++check){
                if(existing[check][i]=='Q'){
                    reject = true;
                    break;
                }
            }
            if(reject){
                continue;
            }

            //search 45 degree conflict 

            for(int check = 0; check < searchIdx;++check){

                int yCheck1 = searchIdx - check - 1;
                if(yCheck1 <0){
                    continue;
                }


                int xCheck1 = i - check - 1;
                if(xCheck1 >=0){
                    if(existing[yCheck1][xCheck1] == 'Q'){
                        reject = true;
                        break;
                    }
                }

                int xCheck2 = i + check + 1;
                if(xCheck2 < existing.size()){
                    if(existing[yCheck1][xCheck2] == 'Q'){
                        reject = true;
                        break;
                    }
                }
            }

            if(reject){
                continue;
            }

            existing[searchIdx][i] = 'Q';
            recFind(ret, existing,searchIdx + 1);
            existing[searchIdx][i] = '.';
        }
    }

};
