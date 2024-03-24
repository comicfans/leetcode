#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {

        int ret = 0;
        pair<int,int> charCount[26]={{0,0}};
        int current = 0;
        int currentHead = 0;
        for(int begin = 0; begin < s.size(); ++begin){

            int c = s[begin] - 'a';

            assert(charCount[c].first <= 2);

            ++charCount[c].first;
            ++current;
            if(charCount[c].first > 2){
                ret = max(ret, current-1);
                //remove char from head to first s[begin] (inclusive)
                
                int newHead = -1;
                for(int j = currentHead; j< begin;++j){
                    int r = s[j] - 'a';
                    if(r != c){
                        charCount[r].first --;
                        assert(charCount[r].first >=0);
                        continue;
                    }
                    charCount[r].first --;
                    newHead = j+1;
                    break;
                }
                current = current - (newHead - currentHead);
                currentHead = newHead;
                continue;
            }

            charCount[c].second = begin;
        }

        ret = max(ret, current);

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        string input = "bcbbbcba";
        auto res = s.maximumLengthSubstring(input);
        assert(res == 4);
    }
    {
        string input = "aaaa";
        auto res = s.maximumLengthSubstring(input);
        assert(res == 2);
    }


}
