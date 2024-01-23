#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numDecodings(string s) {

        vector<int> cache(s.size(),-1);
        
        return recCount(s, 0, cache);
    }

    int recCount(const string& s, int thisIdx,vector<int>& cache){
        if(thisIdx == s.size()){
            return 1;
        }

        if(cache[thisIdx]!=-1){
            return cache[thisIdx];
        }

        //can consume 1 or 2
        //
        int consume1 = s[thisIdx] - '0';
        if(consume1 == 0){
            //impossible no 0 or 0[0-9] valid
            cache[thisIdx] = 0;
            return 0;
        }

        int consume1Res = recCount(s,thisIdx + 1,cache);

        if(consume1>2 || thisIdx == s.size()-1){
            cache[thisIdx] = consume1Res;
            return consume1Res;
        }

        int consume2 = s[thisIdx+1]-'0';

        if(consume1 * 10 + consume2 >26){
            cache[thisIdx]= consume1Res;
            return consume1Res;
        }

        int consume2Res = recCount(s,thisIdx+2,cache);
        cache[thisIdx] = consume1Res + consume2Res;
        return cache[thisIdx];

    }
};
