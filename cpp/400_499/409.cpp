#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {

        sort(s.begin(),s.end());

        int ret = 0;
        int pos = 0;
        while(pos != s.size()){

            int charEnd = upper_bound(s.begin()+pos, s.end(), s[pos]) - s.begin();

            int thisCharCount = charEnd - pos;

            if(thisCharCount %2 == 0){
                ret += thisCharCount ;
                pos = charEnd;
                continue;
            }

            if(ret %2 == 0){
                ret+=thisCharCount;
            }else{
                ret += (thisCharCount /2 * 2);
            }
            pos = charEnd;


        }


        return ret;

        
    }
};
