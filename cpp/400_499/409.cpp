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

        map<char,int> charNumber;
        for(auto c: s){
            charNumber[c]++;
        }

        int res = 0;

        for(const auto kv: charNumber){

            int even = kv.second / 2 * 2;

            res += even;

            if(kv.second == even){
                continue;
            }

            if(res %2 == 0){
                res+=1;
            }


        }

        return res;

        
    }
};
