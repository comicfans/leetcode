#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool checkString(string s) {

        bool hasA=false;
        bool hasB =false;

        for(auto c: s){
            if(c=='a'){
                if(hasB){
                    return false;
                }
                hasA = true;
                continue;
            }

            hasB = true;
        }

        return true;
        
    }
};
