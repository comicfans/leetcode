#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int com = maxCommon(word1,0,word1.size(),word2,0,word2.size());


        return word2.size() + word1.size() - com * 2;


    }

    int maxCommon(const string& s0, int b0,int e0,const string& s1,int b1,int e1){

        if(b0 == e0 || b1 == e1){
            return 0;
        }

        int match1 = maxCommon(s0,b0,e0,s1,b1+1,e1);
        int match2 = maxCommon(s0,b0+1,e0,s1,b1,e1);

        if(s0[b0] != s1[b1]){
            return max(match1,match2);
        }

        int matchN = maxCommon(s0,b0+1,e0,s1,b1+1,e1) + 1;

        int res = max(max(match1, match2),matchN);

        return res;
    }
};

int main(){

    Solution s;
    {
        string word1 = "horse", word2 = "ros";
        assert(s.minDistance(word1, words2) == 3);

    }
}
