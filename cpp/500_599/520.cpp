#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int max = 1;
        for(int i =0;i < word.size(); ++i){
            int thisOne = (bool)isupper(word[i]);
            if(thisOne == max){
                
                continue;
            }
            if(thisOne > max){
                return false;
            }
            if(i>1){
                return false;
            }
            max  =thisOne;
            
            
        }
        return true;
    }
};
