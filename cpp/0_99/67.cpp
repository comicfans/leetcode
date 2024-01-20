#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {

        int sum = int(a.back() - '0')+ int(b.back() - '0');

        string longStr = a.size()>b.size()?a:b;
        string shortStr = a.size()>b.size()?b:a;

        longStr.back() = sum % 2 + '0';
        sum = sum >=2 ;

        int pos = 1;
        while(pos < longStr.size()){
            int fromShort = 0;
            if(pos < shortStr.size()){
                fromShort = shortStr[shortStr.size()-1-pos] - '0';
            }

            int thisRes = longStr[longStr.size()-1 - pos]  - '0' + sum + fromShort;
            
            longStr[longStr.size()-1-pos] = thisRes % 2 + '0';

            sum = thisRes >= 2;
            ++pos;

            if(sum==0 && pos >= shortStr.size()){
                break;
            }
        }

        if(sum > 0){
            longStr=  '1'+longStr;
        }
        return longStr;
        
    }
};

int main(){
    Solution s;
    {
        string a = "11", b = "1";
        assert(s.addBinary(a,b) == "100");
    }
    {
        string a = "1010", b = "1011";
        assert(s.addBinary(a,b) == "10101");
    }
}
