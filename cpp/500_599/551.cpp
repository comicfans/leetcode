#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        
        int absent = 0;
        int late = 0;
        for(auto c: s){
            if(c == 'P'){
                late = 0;
                continue;
            }
            if(c == 'A'){
                ++absent;
                if(absent >= 2){
                    return false;
                }
                late = 0;
                continue;
            }

            if(c == 'L'){
                ++late;
                if(late >= 3){
                    return false;
                }
            }
        }
        return true;
    }
};
