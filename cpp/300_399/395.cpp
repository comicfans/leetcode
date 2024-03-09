#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {

        int best = 0;
        for(int start = 0; start < s.size(); ++start){

            if(s.size() - start <= best){
                break;
            }

            int counts[26] = {0};

            int lessThanNumber = 0;

            for(int end = start; end < s.size(); ++end){
                int cIdx = s[end] - 'a';

                bool newChar = false;

                assert(counts[cIdx]>=0);

                if(counts[cIdx] == 0){
                    ++lessThanNumber;
                }

                counts[cIdx]++;
                if(counts[cIdx]==k){
                    --lessThanNumber;
                }

                if(lessThanNumber == 0){
                    best = max(best, end - start + 1);
                }
            }
        }


        return best;
        
    }
};

int main(){
    Solution s;
    {
        string input = "ababbc";int k = 2;
        assert(s.longestSubstring(input,k) == 5);
    }
    {
        string input  = "aaabb";int k = 3;
        assert(s.longestSubstring(input,k) == 3);
    }
}
