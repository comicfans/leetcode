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
        for(int i = 0;i<s.size(); ++i){

            int pos = t.find(s[i]);

            ret += abs(pos - i);
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

