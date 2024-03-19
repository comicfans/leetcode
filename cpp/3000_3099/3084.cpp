#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long countSubstrings(string s, char c) {

        vector<int> pos;
        for(int i = 0; i< s.size(); ++i){

            if(s[i] == c){
                pos.push_back(i);
            }
        }

        long long  ret = ((long long)(pos.size()) + 1) * ((long long) (pos.size())) / 2;



        return ret;
    }
};
