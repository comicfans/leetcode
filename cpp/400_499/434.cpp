#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countSegments(string s) {

        int ret = 0;

        for(int i = 0; i< s.size(); ++i){
            if(s[i] == ' '){
                if(i == 0){
                    continue;
                }

                if(s[i-1]!= ' '){
                    ++ret;
                }

                continue;
            }
        }

        if(s.size()>0 && s.back() != ' '){
            ++ret;

        }

        return ret;
        
    }
};
