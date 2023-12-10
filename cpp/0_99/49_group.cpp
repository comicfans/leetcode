#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {


        map<string, vector<string>> m;

        for(const string& s: strs){
            string copy = s;
            sort(copy.begin(),copy.end());

            m[copy].push_back(s);
        }


        vector<vector<string>> ret;
        for(auto& kv: m){
            ret.push_back(kv.second);
        }
        return ret;
    }
};
