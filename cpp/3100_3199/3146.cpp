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
    int findPermutationDifference(string s, string t) {

        int ret = 0;
        int idx[26];
        for(int i = 0;i<s.size(); ++i){

            idx[s[i] - 'a'] = i;
        }

        for(int i = 0;i<s.size(); ++i){

            ret += abs(i - idx[t[i] - 'a']);
        }


        return ret;

        
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

