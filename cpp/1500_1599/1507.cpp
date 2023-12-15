#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string reformatDate(string date) {

        auto firstSpace = date.find(' ');

        auto secondSpace = date.find(' ', firstSpace + 1);

        auto firstNonDigit = find_if(date.begin(),date.end(),[](auto c){

            if(c>='0' && c<='9'){
                return false;
            }

            return true;
        }) - date.begin();

        string day = date.substr(0, firstNonDigit);

        auto mon = date.substr(firstSpace+1, secondSpace - firstSpace - 1);

        map<string, string> mon_num = {
            {"Jan"  ,  "01"},
            {"Feb"  ,  "02"},
            {"Mar"  ,  "03"},
            {"Apr"  ,  "04"},
            {"May"  ,  "05"},
            {"Jun"  ,  "06"},
            {"Jul"  ,  "07"},
            {"Aug"  ,  "08"},
            {"Sep"  ,  "09"},
            {"Oct"  ,  "10"},
            {"Nov"  ,  "11"},
            {"Dec"  ,  "12"},
        };

        auto year = date.substr(secondSpace + 1);


        return year+"-"+mon_num.at(mon)+"-"+(day.size()==1?"0"+day: day);
    }
};
