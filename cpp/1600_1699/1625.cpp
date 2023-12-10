#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    int gcd(int a,int b){
        int maxOne = max<int>(a, b);
        int minOne = min<int>(a, b);
        while((maxOne % minOne != 0)&& (minOne > 1)){
            int mod = maxOne % minOne;
            maxOne = minOne;
            minOne = mod;
        }

        return minOne;

    }
    string findLexSmallestString(string s, int a, int b) {

        //first we need to tell if we can shift b to make 0 index to 1 index

        //that is (b x N) % s.size() == 1
        //
        //if b and s.size() gcd == 1
        int bSizeGcd = gcd(s.size(), b);


        vector<string> canReach;
        canReach.push_back(s);

        int tenAGcd = gcd(a,10);
        int circle = 10 * a / tenAGcd ;
        
        for(int i = 0;i < circle;++i){
            string copy = canReach.back();
            for(auto &c : copy){
                c = (c- '0' + a) % 10 + '0';
            }
            canReach.push_back(copy);
        }



        if(bSizeGcd == 1){
            //every digits can be moved to odd and modified by a, so check any
            //str of canReach has least digits, make it 0 index
        }


        
    }
};
