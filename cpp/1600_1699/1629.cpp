#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {


        int prev = 0;

        int best = 0;
        char bestChar = 0;

        for(int i = 0;i<releaseTimes.size();++i){
            auto ch = keysPressed[i];
            auto dur = releaseTimes[i] - prev;

            if(dur > best){
                bestChar = ch;
                best = dur;
            }else if(dur == best){
                if(ch > bestChar){
                    bestChar = ch;
                }
            }
            prev = releaseTimes[i];
            
        }
        return bestChar;

        
    }
};
