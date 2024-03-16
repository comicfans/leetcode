#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> charNumber;
        for(auto c:s){
            charNumber[c]++;
        }
        vector<pair<char,int>> sorted(charNumber.begin(),charNumber.end());
        sort(sorted.begin(),sorted.end(),[](const auto lhs, const auto rhs){
                return lhs.second > rhs.second;
        });
        string ret;

        for(auto kv: sorted){
            ret+= string(kv.second,kv.first);
        }
        return ret;
    }
};
