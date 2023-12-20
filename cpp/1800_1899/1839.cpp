#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestBeautifulSubstring(string word) {

        char state[] = "aeiou ";

        int current = 0;
        int aBeginPos = -1;
        int best = 0;

        for(int i = 0; i < word.size();++i ){

            char c = word[i];
            if(find(state,state+5,c)== state + 5){
                //not aeiou
                if(state[current] == ' '){
                    //already complete u stage
                    int thisLength = i - aBeginPos;
                    best = max(best,thisLength);
                    aBeginPos = -1;
                    current = 0;
                }
                continue;
            }

            //is one of aeiou
            if(state[current]!= c){
                if(current == 0){
                    // a not found
                    aBeginPos = -1;
                    current = 0;
                    continue;
                }

                if(c == state[current - 1]){
                    continue;
                }else{

                    if(state[current] == ' '){
                        int thisLength = i - aBeginPos;
                        best = max(best,thisLength);
                    }


                    aBeginPos = -1;
                    current = 0;

                    if(c == 'a'){
                        aBeginPos = i;
                        current = 1;
                    }

                    continue;
                }
            }

            if(c == 'a'){
                if(aBeginPos==-1){
                    aBeginPos = i;
                }
            }

            ++current;
        }

        if(state[current] == ' '){
            int thisLength = word.size() - aBeginPos;
            best = max(best,thisLength);
        }

        return best;
        
    }
};

int main(){

    Solution s;
    {
        string input = "aeiaaioaaaaeiiiiouuuooaauuaeiu";
        assert(s.longestBeautifulSubstring(input) == 13);
    }
{
        string input = "aeeeiiiioooauuuaeiou";
        assert(s.longestBeautifulSubstring(input) == 5);
    }
    {
        string input = "a";
        assert(s.longestBeautifulSubstring(input) == 0);
    }
}
