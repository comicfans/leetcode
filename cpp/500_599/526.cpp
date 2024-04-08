#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countArrangement(int n) {

        vector<set<int>> possible(n);

        for(int i = 0; i < n; ++i){

            int v = i+1;

            bool atLeastOne = false;
            for(int j = 1; j<=n; ++j){
                if(j % v == 0 || v % j == 0){
                    possible[i].insert(j);
                    atLeastOne = true;
                }
            }
            if(!atLeastOne){
                return 0;
            }
        }

        set<int> used;
        return rec(possible, 0,used);
    }

    int rec(const vector<set<int>>& possible, int idx, set<int>& used){
        if(idx == possible.size()){
            return 1;
        }

        if(possible[idx].empty()){
            return 0;
        }

        int ret = 0;
        for(auto p : possible[idx]){
            if(used.contains(p)){
                continue;
            }

            auto ins = used.insert(p);
            int sub = rec(possible, idx+1, used);

            ret += sub;

            used.erase(ins.first);
        }

        return ret;

    }
};
