#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countTime(string time) {

        auto hStr = time.substr(0,2);

        int hPos = 1;
        if(hStr == "??"){
            hPos = 24;
        }else if(hStr[0] == '?'){
            hPos = 2;
            if(hStr[1]<'4'){
                hPos=3;
            }
        }else if(hStr[1] == '?'){
            if(hStr[0] == '2'){
                hPos = 4;
            }else {
                hPos = 10;
            }
        }

        auto mStr = time.substr(3);
        int mPos = 1;
        if(mStr == "??"){
            mPos = 60;
        }else if(mStr[0] == '?'){
            mPos = 6;
        }else if(mStr[1] == '?'){
            mPos = 10;
        }

        return mPos * hPos;
            
    }
};
