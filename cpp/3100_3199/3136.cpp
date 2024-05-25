#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


#ifdef LEETCODE
#include "../parse.h"
#endif 




class Solution {
public:
    bool isValid(string word) {
        
        if(word.size() < 3){
            return false;
        }

        string vo = "aeiou";
        bool hasVo = false;
        bool hasNonVo = false;
        for(auto c : word){
            if(isdigit(c)){
                continue;
            }
                if(!isalpha(c)){
                    return false;
                }
            auto lower = tolower(c);
            if(vo.find(lower)!=string::npos){
                hasVo = true;
            }else{
                hasNonVo = true;
            }
        }
        return hasVo && hasNonVo;
    }
};







#ifdef LEETCODE
int main(){
    Solution s;
    {
        //VI = {};
        //VVI = {};
    }
    {
        //VI = {};
        //VVI = {};
    }
}
#endif 

