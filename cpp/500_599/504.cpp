#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        string ret;
        int absV = abs(num);
        while(absV >= 0){
            ret.push_back('0' + absV % 7);
            absV /= 7;
            if(absV == 0){
                break;
            }
        }
        if(num < 0){
            ret.push_back('-');
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
