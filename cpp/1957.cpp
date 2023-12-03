#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3){
            return s;
        }

        char last2[]  = {s[0],s[1]};


        string ret = {s[0],s[1]};
        for(int i = 2;i<s.size();++i){
            if(s[i] == last2[0] && s[i]== last2[1]){
                continue;
            }

            last2[i%2] = s[i];
            ret.push_back(s[i]);
        }
        return ret;
        
    }
};
int main(
){
    Solution s;
    {
        s.makeFancyString("leeetcode");
    }
}
