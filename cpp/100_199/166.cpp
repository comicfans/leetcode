#include <vector>
#include <sstream>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerat, int denominat) {

        int sign = (numerat >= 0?1:-1) * (denominat >=0?1:-1);

        long long numerator = abs((long long)numerat) ;
        long long denominator = abs((long long)denominat);


        long long integerPart = numerator / denominator;

        vector<long long> left = {(numerator - integerPart * denominator)*10};

        stringstream ss;
        ss<<integerPart; 
        string integerStr;
        ss>>integerStr;

        int repeatStart = -1;
        while(left.back()!=0){
            if(left.size()==1){
                integerStr.push_back('.');
            }

            int digit = left.back() / denominator;

            integerStr.push_back(digit + '0');

            long long thisLeft = (left.back() - digit*denominator)*10;

            auto existing = find(left.begin(),left.end(),thisLeft);

            if(existing == left.end()){
                left.push_back(thisLeft);
                continue;
            }

            repeatStart = existing - left.begin();
            break;
        }

        if(sign <0 && integerStr != "0"){
            integerStr.insert(integerStr.begin(),'-');
        }

        if(repeatStart == -1){
            return integerStr;
        }

        integerStr.insert(integerStr.end()-(left.size()-repeatStart),'(');
        integerStr.push_back(')');


        
        return integerStr;
        
    }
};

int main(){
    Solution s;
    {
        int num=
-1,
        den=
-2147483648;
        assert(s.fractionToDecimal(num,den) == "0.0000000004656612873077392578125");
    }
    {
        int num = -22,den = -2;
        assert(s.fractionToDecimal(num,den) == "11");
    }
    {
        int num = -50,den = 8;
        assert(s.fractionToDecimal(num,den) == "-6.25");
    }
    {
        int num = 4,den = 333;
        assert(s.fractionToDecimal(num,den) == "0.(012)");
    }
    {
        int num = 1,den = 2;
        assert(s.fractionToDecimal(num,den) == "0.5");
    }
    {
        int num = 2,den = 1;
        assert(s.fractionToDecimal(num,den) == "2");
    }
    {
        int num = 0, den = -5;
        assert(s.fractionToDecimal(num,den)=="0");
    }
    
}
