#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

        vector<pair<int,string>> numSym= {
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


    int romanToInt(string s) {

             // str is made up by  combination of sym
        // so just pick one match, and assume next match have different weight
        //

        if(s.empty()){
            return 0;
        }

        int thisWeight = 1000;
        return recMatch(s, 0, thisWeight, 0 );
    }

    int recMatch(const string& s, int startPos, int thisWeight, int existing){
        //always consume big one
        //
        if(startPos == s.size()){
            return existing;
        }

        for(int i =0;i< numSym.size();++i){
            auto str = numSym[i].second;
            if(equal(str.begin(),str.end(),s.begin()+startPos)){
                existing += numSym[i].first;
                return recMatch(s, startPos + str.size(), thisWeight / 10, existing);
            }
        }

        assert(false);
    }

};
