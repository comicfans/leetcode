#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {

        for(int pos = num.size()-1;pos>=0;--pos){
            int value = num[pos] - '0';
            if(value %2 != 0){
                return num.substr(0, pos+1);
            }
        }

        return "";
        
    }
};
