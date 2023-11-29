#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {

        map<char,int> v;

        for(int i =0;i<s.size();++i){
            auto pos = v.find(s[i]);
            if(pos!= v.end()){
                v[s[i]]=i;
                continue;
            }
            pos->second = -1;
        }

        int minIdx = numeric_limits<int>::max();
        for(auto kv: v){
            if(kv.second == -1){
                continue;
            }

            minIdx = min(minIdx, kv.second);
        }

        return minIdx == numeric_limits<int>::max()?-1:minIdx;

        
    }
};
