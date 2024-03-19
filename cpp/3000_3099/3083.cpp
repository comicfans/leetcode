#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isSubstringPresent(string s) {

        string rev = s;
        reverse(s.begin(),s.end());

        for(int i = 0;i< s.size()-1; ++i){
            auto sub = s.substr(i,2);

            if(rev.find(sub)!=string::npos){
                return true;
            }

        }

        return false;
        
    }
};
