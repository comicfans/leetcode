#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {

        vector<int> ret(k);

        map<int,set<int>> userUam;
        for(const auto& log: logs){
            userUam[log[0]].insert(log[1]);
        }

        for(const auto& kv: userUam ){
            int uam = kv.second.size();
            if(uam > k){
                continue;
            }
            ret[uam-1] ++ ;
        }

        return ret;
        
    }
};
