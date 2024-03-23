#include <regex>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string validIPAddress(string queryIP) {

        regex ipv4("(^[0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})$");

        smatch v4Res;
        if(regex_match(queryIP, v4Res, ipv4)){

            for(const auto digit : v4Res){

                string str = digit;
                auto integer = stoi(str);

                if(integer == 0 && str.size()!=1){
                    return "Neither";
                }

                if(integer >= 256){
                    return "Neither";
                }

                if(str[0] == '0' && integer != 0){
                    return "Neither";
                }

            }


            return "IPv4";

        }

        regex ipv6 ("^([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4}):([0-9a-fA-F]{1,4})$");

        smatch v6Res;
        if(!regex_match(queryIP, v6Res, ipv6)){
            return "Neither";
        }

        return "IPv6";

        
    }
};

int main(){
    Solution s;
    {
        string input = "192.0.0.1";
        auto res = s.validIPAddress(input);
        assert(res == "IPv4");
    }
    {
        string input = "172.16.254.1";
        auto res = s.validIPAddress(input);
        assert(res == "IPv4");
    }
{
        string input = "2001:0db8:85a3:0:0:8A2E:0370:7334";
        auto res = s.validIPAddress(input);
        assert(res == "IPv6");
    }
{
        string input = "256.256.256.256";
        auto res = s.validIPAddress(input);
        assert(res == "Neither");
    }
}
