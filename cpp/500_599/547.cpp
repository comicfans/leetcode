#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        set<int> unwalk;
        for(int i = 0;i<isConnected.size(); ++i){
            unwalk.insert(i);
        }

        int ret = 0;

        for(int i = 0; i < isConnected.size(); ++i){

            if(!unwalk.contains(i)){
                continue;
            }

            ++ret;
            walk(i, isConnected, unwalk);
        }
        
        return ret;
    }

    void walk(int i , const vector<vector<int>>& isConnected, set<int>& unwalked){

        auto pos = unwalked.find(i);
        assert(pos != unwalked.end());

        unwalked.erase(pos);

        for(int j = 0;j < isConnected.size(); ++j){

            if(i == j){
                continue;
            }

            if(isConnected[i][j] && unwalked.contains(j)){
                walk(j, isConnected, unwalked);
            }
        }

    }
};
