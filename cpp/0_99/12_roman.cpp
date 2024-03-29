#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {

        if(num == 0){
            return "";
        }

        map<int,string> numSym= {
        {3000,"MMM"},
        {2000,"MM"},
        {1000,"M"},
        {900,"CM"},
        {800,"DCCC"},
        {700,"DCC"},
        {600,"DC"},
        {500,"D"},
        {400,"CD"},
        {300,"CCC"},
        {200,"CC"},
        {100,"C"},
        {90,"XC"},
        {80,"LXXX"},
        {70,"LXX"},
        {60,"LX"},
        {50,"L"},
        {40,"XL"},
        {30,"XXX"},
        {20,"XX"},
        {10,"X"},
        {9,"IX"},
        {8,"VIII"},
        {7,"VII"},
        {6,"VI"},
        {5,"V"},
        {4,"IV"},
        {3,"III"},
        {2,"II"},
        {1,"I"},
        {0,""}
        };

        vector<string> ret;
        int weight = 1;
        while(num>0){
            auto last = num %10;
            auto key = last * weight;
            ret.push_back(numSym.at(key));
            weight *= 10;
            num /= 10;
        }


        string str = ret.back();
        ret.pop_back();
        while(!ret.empty()){
            str = str+ ret.back();
            ret.pop_back();
        }
        return str;
        
    }
};
