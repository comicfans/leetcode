#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        return rec(s,0,(int)s.size(),0);

    }

    int rec(const string& s, int startPos, int revMatchEnd, int currentLen){
        assert(startPos < revMatchEnd);

        int subBest = currentLen;

        for(int tryPos = startPos; tryPos < revMatchEnd; ++tryPos){

            if(tryPos > startPos && s[tryPos]== s[tryPos- 1]){
                // bbcbb
                continue;
            }

            if(revMatchEnd - tryPos  + currentLen <= subBest){
                break;
            }


            char thisChar = s[tryPos];

            int rMatch = find(s.rbegin() + ((int)s.size() - revMatchEnd),  s.rbegin() + (s.size()-1 - tryPos), thisChar) - s.rbegin();

            rMatch = (int)s.size() - 1- rMatch;

            assert(s[rMatch] == thisChar);

            if(rMatch == tryPos){
                int thisRes = currentLen + 1;
                subBest = max(subBest, thisRes);
                continue;
            }

            if(rMatch == tryPos + 1){
                int thisRes = currentLen + 2;
                subBest = max(subBest, thisRes);
                continue;
            }

            int subRec = rec(s, tryPos + 1, rMatch, currentLen + 2);

            subBest = max(subBest, subRec);
        }

        return subBest;
    }
};

int main(){
    Solution s;
    {
        string input = "aaa";
        auto res = s.longestPalindromeSubseq(input);
        assert(res == 3);
    }
    {
        string input = "aabaa";
        auto res = s.longestPalindromeSubseq(input);
        assert(res == 5);
    }
    {
        string input = "cbbd";
        auto res = s.longestPalindromeSubseq(input);
        assert(res == 2);
    }
    {
        string input = "bbbab";
        auto res = s.longestPalindromeSubseq(input);
        assert(res == 4);
    }

}
