#include <cwctype>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {

        int leftMore = 0;
        int existing = 0;

        return recFind(s,0,leftMore,existing)*2;
        
    }

    int recFind(const string& s, int thisPos, int leftMore, int existingPair){

        bool firstTry = (leftMore == 0) && (existingPair == 0);

        int bestSub = leftMore?0:existingPair;

        if(firstTry){
            auto pos = s.find('(',thisPos);
            while(pos!= string::npos){

                int thisBest = recFind(s, pos+1, leftMore+1, existingPair);
                bestSub = max(bestSub, thisBest);
                pos = s.find('(',pos+1);
            }

            return bestSub;
        }

        if(thisPos == s.size()){
            return leftMore>0?0:existingPair;
        }


        bool tryRight = (leftMore > 0);

        int leftChar = s.size() - thisPos;

        bool tryLeft = leftChar >= leftMore + 2;

        if(tryLeft && (s[thisPos] == '(')){
            int leftRes = recFind(s, thisPos+1, leftMore+1, existingPair);
            bestSub = max(bestSub, leftRes);
        }

        if(tryRight && (s[thisPos] == ')')){
            int rightRes = recFind(s,thisPos+1, leftMore -1, existingPair + 1);
            bestSub =max(bestSub, rightRes);
        }

        
        return bestSub;

    }
};

int main(){
    Solution s;

    {
        assert(s.longestValidParentheses("()(()(((") == 2);
        assert(s.longestValidParentheses("(()") == 2);
        assert(s.longestValidParentheses("()") == 2);
        assert(s.longestValidParentheses(")()())") == 4);
        assert(s.longestValidParentheses("()(()") == 2);
    }
    {
    }
}
