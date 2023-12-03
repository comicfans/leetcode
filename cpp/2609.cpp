#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {

        int best = 0;
        for(int begin = 0; begin < s.size(); ++ begin){
            for(int end = begin + 2; end <= s.size();end+=2){
                int length  = end - begin ;

                if(s.substr(begin,length/2) == string(length/2,'0') && s.substr(begin + length/2,length/2) == string(length/2,'1')){
                    best = max(best,length);
                    break;
                }

            }
        }

        return best;
        
    }
};
int main(){
    Solution s;
    {
        assert(s.findTheLongestBalancedSubstring("01000111") == 6);
        assert(s.findTheLongestBalancedSubstring("00111") == 4);
    }
}
