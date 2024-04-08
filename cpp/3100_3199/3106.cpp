#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string getSmallestString(string s, int k) {

        string ret = s;

        for(int i = 0; i< s.size() && k> 0; ++i){

            char from = s[i];

            if(from + k <= 'z'){
                //only left is possible
                char lowest = max((int)'a', (int)from - k);

                int spend = abs(lowest - from);
                k -= spend;
                ret[i] = lowest;
                continue;
            }

            //from +k can be 'a'
            
            char leftLowest = max((int)'a', (int)from - k);
            int leftSpend = abs(leftLowest - from);

            char rightLowest = 'a';
            int rightSpend = 'z' - from + 1;

            if(leftLowest != 'a'){
                k -= rightSpend;
                ret[i] = 'a';
                continue;
            }

            ret[i] = 'a';
            k -= min(leftSpend, rightSpend);

        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        string input = "zbbz";
        auto res = s.getSmallestString(input, 3);
        assert(res == "aaaz");
    }
    {
        string input = "xaxcd";
        auto res = s.getSmallestString(input, 4);
        assert(res == "aawcd");
    }
    {
        string input = "lol";
        auto res = s.getSmallestString(input, 0);
        assert(res == "lol");
    }
}
