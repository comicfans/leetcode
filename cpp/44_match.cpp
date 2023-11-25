#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        //reduce *****
        //
        string simplified;
        for(int i =0;i<p.size();++i){
            if(p[i] != '*'){
                simplified.push_back(p[i]);
                continue;
            }
            //is star, and not first
            if(!simplified.empty() && (simplified.back() == '*')){
                continue;
            }else{
                simplified.push_back(p[i]);
            }

        }
        
        return recMatch(s,0,simplified,0);
    }

    bool recMatch(const string& s, int sPos, const string& p, const int pPos){

        if((pPos == p.size()) && (sPos != s.size())){
            return false;
        }

        if(sPos == s.size()){
            if(pPos == p.size()){
                return true;
            }else{
                //left partten must be only 1 star
                return (p[pPos] == '*') && (pPos == p.size()-1);
            }
        }

        assert(sPos < s.size());



        if((p[pPos] != '?')&& (p[pPos]!='*')){

            if(p[pPos] == s[sPos]){
                return recMatch(s, sPos+1, p, pPos+1);
            }else{
                return false;
            }
        }

        if(p[pPos] == '?'){
            return recMatch(s, sPos + 1, p, pPos+1);
        }
        // is "*"
        if(pPos == p.size()-1){
            return true;
        }

        //can't consume too much 
        int leftNoneStar = 0;
        for(int i= pPos+1;i< p.size();++i){
            if(p[i]!='*'){
                ++leftNoneStar;
            }
        }

        int maxConsume = s.size();
        maxConsume -= sPos;
        maxConsume -= leftNoneStar;


        for(int consumeN = 0; consumeN <= maxConsume; ++ consumeN){
            if(recMatch(s,sPos+consumeN, p,pPos + 1)){
                return true;
            }
        }
        return false;

    }
};

int main(){
    Solution s;
{
        string str ="abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
        string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
        s.isMatch(str, p);
    }
    {
        assert(s.isMatch("aa","*"));
    }
    {
        assert(!s.isMatch("b","*?*?"));
    }
    
}
