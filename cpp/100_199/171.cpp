#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {

        int ret = 0;

        for(auto c: columnTitle){

            int number = (c - 'A' + 1 ) ;
            ret = ret * 26 ;
            ret += number;
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        assert(s.titleToNumber("Z") == 26);
        assert(s.titleToNumber("AA") == 27);
        assert(s.titleToNumber("ZY") == 701);
    }
}
