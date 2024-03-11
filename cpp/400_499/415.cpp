#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {

        int fromLower = 0;
        string ret;

        for(int pos = 0;pos < max(num1.size(), num2.size()); ++pos){


            int v1 = (pos < num1.size()?num1[num1.size()-1 -pos]-'0':0);
            int v2= (pos < num2.size()? num2[num2.size()-1 -pos] - '0':0);

            int res = v1 + v2 + fromLower;

            fromLower = (res >= 10);


            ret.push_back(res % 10 + '0');
        }
        if(fromLower > 0){
            ret.push_back('1');
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }
};
