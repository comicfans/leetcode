#include <vector>
#include <cassert>
#include <string>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size()){return false;}
        vector<int> modLast(26);

        for(int i =0;i<s.size();++i){
            if(s[i]==t[i]){
                continue;
            }

            int diff = (t[i] - s[i] + 26) % 26;


            if(modLast[diff] == 0){
                modLast[diff] = diff;
            }else{
                modLast[diff] += 26;
            }

            if(modLast[diff] > k){
                return false;
            }

        }
        return true;
    }
};
