#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minChanges(string s) {


        int ret = 0;

        char prev = 0;
        for(int i = 0;i < s.size(); ++i){

            if(i % 2 == 0){
                //even begin, can be any 
                prev = s[i];
                continue;
            }

            if(s[i]!= prev){
                ++ret;
            }

        }
        return ret;
    }
};
