#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tSearch = -1;
        for(int i = 0; i< s.size(); ++i){
            tSearch = t.find(s[i],tSearch+1);
            if(tSearch == string::npos){
                return false;
            }
        }
        return true;
    }
};
