#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
       
        unsigned int cast = (unsigned int)num;

        string ret;

        char hexMap [] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(cast > 0){

            int mod = cast % 16;
            ret.push_back(hexMap[mod]);
            cast /= 16;
        }

        reverse(ret.begin(),ret.end());


        return ret;
        
    }
};

int main(){
    Solution s;
    {
        auto res = s.toHex(-1);
        assert(res == "ffffffff");
    }
    {
        auto res = s.toHex(26);
        assert(res == "1a");
    }
}
