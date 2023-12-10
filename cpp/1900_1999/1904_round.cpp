#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    int str2Time(const string& str){

        auto hhStr = str.substr(0,2);
        auto mmStr = str.substr(3);

        stringstream hhs(hhStr);
        stringstream mms(mmStr);

        int hh;
        int mm;
        hhs>>hh;
        mms>>mm;

        return hh*60+mm;

    }

    int numberOfRounds(string loginTime, string logoutTime) {

        int begin = str2Time(loginTime);
        int end = str2Time(logoutTime);

        if(begin > end){
            end += 24 * 60;
        }


        int beginIdx = (begin + 14)/ 15;
        int endIdx = end / 15;
        
        return max(endIdx - beginIdx,0) ;
    }
};

int main(){
    Solution s;
    {
        auto res = s.numberOfRounds("21:30","03:00");
        assert(res == 22);
    }
{
        auto res = s.numberOfRounds("09:31","10:14");
        assert(res == 1);
    }
}
