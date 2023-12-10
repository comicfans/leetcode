#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int number = words.size();
        map<char,int> charCount;
        for(auto& v:words){
            for(auto c:v){
                charCount[c]++;
            }
        }

        for(auto kv:charCount){
            if(kv.second % number != 0){
                return false;
            }
        }

        return true;
        
    }
};
