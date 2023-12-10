#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes) {

        auto pos = find_if(dominoes.begin(),dominoes.end(), [](auto ch){
            return ch == 'L' || ch == 'R';
        });

        bool consumeLeft = false;

        while(pos != dominoes.end()){

            if(*pos=='L'){
                //turn left dot to 'L' 

                if(!consumeLeft){
                for(int i = pos - dominoes.begin() -1;i>=0;--i){
                    if(dominoes[i]=='.'){
                        dominoes[i]='L';
                    }else{
                        break;
                    }
                }
                }

                consumeLeft = false;
                pos = find_if(pos+1,dominoes.end(), [](auto ch){
                    return ch == 'L' || ch == 'R';
                });

                continue;
            }

            //is right, find next one
            auto nextPos = find_if(pos+1,dominoes.end(), [](auto ch){
                    return ch == 'L' || ch == 'R';
            });

            if(nextPos == dominoes.end()){
                //turn right to R
                fill(pos+1,dominoes.end(),'R');
                break;
            }
            
            if(*nextPos == 'L'){
                int inRangeLength = nextPos - pos - 1;

                fill_n(pos+1, inRangeLength/2, 'R');

                fill_n(nextPos - inRangeLength/2,inRangeLength/2,'L');
                consumeLeft = true;
            }else{
                fill(pos+1,nextPos,'R');
                consumeLeft = false;
            }

            pos = nextPos;
        }
        
        return dominoes;
    }
};

int main(){
    Solution s;
    {

        string input = "L.LL......";
        auto res = s.pushDominoes(input);
        assert(res == "LLLL......");
    }
    {
        string input = "RR.L";
        auto res = s.pushDominoes(input);
        assert(res == "RR.L");
    }
    {
        string input = ".L.R...LR..L..";
        auto res = s.pushDominoes(input);
        assert(res == "LL.RR.LLRRLL..");
    }
    {

        string input = "L.....RR.RL.....L.R.";
        auto res = s.pushDominoes(input);
        assert(res == "L.....RRRRLLLLLLL.RR");
    }
}
