#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(), magazine.end());

        int mIdx = 0;
        for(int rIdx = 0; rIdx < ransomNote.size(); ++rIdx){
            auto pos = lower_bound(magazine.begin()+mIdx, magazine.end(), ransomNote[rIdx]);
            if(pos == magazine.end()){
                return false;
            }
            if(*pos != ransomNote[rIdx]){
                return false;
            }
            mIdx = pos - magazine.begin()+1;
        }
        return true;
    }
};
