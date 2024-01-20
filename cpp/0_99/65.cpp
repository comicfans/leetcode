#include <vector>
#include <regex>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        std::regex regInt("^[+-]{0,1}[0-9]{1,}$");
        std::regex regDec("^[+-]{0,1}[0-9]*(\\.([0-9]{1,}){0,1}){0,1}");

        auto ePos = s.find_first_of("eE");

        if(ePos == string::npos){
            if(regex_match(s,regInt)){
                return true;
            }
            if(regex_match(s,regDec) && isDec(s)){
                return true;
            }
            return false;
        }

        auto firstPart = s.substr(0,ePos);
        auto secondPart = s.substr(ePos+1,s.size()-ePos - 1);

        if(!regex_match(secondPart,regInt)){
            return false;
        }

        if(regex_match(firstPart, regInt)){
            return true;
        }

        if(regex_match(firstPart, regDec) && isDec(firstPart)){
            return true;
        }       
        return false;
    }

    bool isDec(std::string str){
        if(str.empty()){
            return false;
        }
        if(str[0] == '+'|| str[0] == '-'){
            str = str.substr(1);
        }

        if(str.empty()){
            return false;
        }

        auto dotPos = str.find('.');
        if(dotPos == string::npos){
            return true;
        }

        return str.size()- 1 > 0;

    }
};

int main(){
    Solution s;
    {
        vector<string> valid = {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
        vector<string> invalid = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};

        for(auto v: valid){
            assert(s.isNumber(v));
        }
        for(auto v: invalid){
            assert(!s.isNumber(v));
        }
    }
}

