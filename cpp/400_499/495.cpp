#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int ret = 0;

        int attackHead = timeSeries[0];
        int attackEnd = timeSeries[0] + duration - 1;

        for(int pos = 1;pos < timeSeries.size();){


            auto ub = upper_bound(timeSeries.begin() + pos ,timeSeries.end(), attackEnd ) - timeSeries.begin();

            if(ub == pos){
                //not connect

                ret += (attackEnd - attackHead + 1);

                attackHead = timeSeries[pos];
                attackEnd = timeSeries[pos] + duration - 1;
                pos++;
                continue;
            }

            --ub;
            attackEnd = timeSeries[ub]+ duration - 1;
            pos = ub + 1;
        }

        ret += (attackEnd - attackHead + 1);

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> ts = {1,2};
        auto res = s.findPoisonedDuration(ts, 2);
        assert(res == 3);
    }
    {
        vector<int> ts = {1,4};
        auto res = s.findPoisonedDuration(ts, 2);
        assert(res == 4);
    }
}
