#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret ;

        while(columnNumber>0){
            int mod = columnNumber % 26;

            // A .... .Z AA ....   AZ
            // 1 ...  26 27 ...    52
            //
            // 0 ...  25 26 .....  51
            //
            ret.push_back((mod -1 +26)%26+'A');
            columnNumber = (columnNumber -1)/ 26;
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(){
    Solution s;
    {
        assert(s.convertToTitle(26) == "Z");
    }
    {
        assert(s.convertToTitle(27) == "AA");
    }
    {
        assert(s.convertToTitle(701) == "ZY");
    }
}
