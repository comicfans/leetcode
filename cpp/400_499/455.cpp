#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ret = 0;

        if(s.empty()){
            return 0;
        }

        int sIdx = -1;
        for(int gIdx = 0;gIdx < g.size(); ++gIdx){

            sIdx = lower_bound(s.begin() + sIdx +1 ,s.end(), g[gIdx]) - s.begin();

            if(sIdx == s.size()){
                break;
            }

            ++ret;
        }

        return ret;
        
    }
};
