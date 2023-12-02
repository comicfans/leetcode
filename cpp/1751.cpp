#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {


        vector<int> chain;
        return recFind(events,k,chain,0);
    }

    int recFind(const vector<vector<int>>& events, int k, vector<int>& chain, int currentSum){
        if(k == 0){
            return currentSum;
        }

        //pick any possible

        int best = currentSum;
        for(int tryIdx = chain.empty()?0:chain.back()+1; tryIdx < events.size(); ++ tryIdx){

            auto& ev = events[tryIdx];

            bool hasOverlap = false;
            for(int checkOverlap = 0;checkOverlap < chain.size();++checkOverlap){

                auto& picked = events[chain[checkOverlap]];

                if(max(ev[0],picked[0]) <= min(ev[1],picked[1])){
                    hasOverlap = true;
                    break;
                }
            }

            if(hasOverlap){
                continue;
            }

            chain.push_back(tryIdx);
            currentSum += ev[2];

            int thisRes = recFind(events, k-1, chain, currentSum);

            best = max(thisRes, best);
            currentSum -= ev[2];
            chain.pop_back();
        }

        return best;
    }
};

int main(){
    Solution s;
    {

        vector<vector<int>> input= {{1,2,4},{3,4,3},{2,3,1}};
        int k = 2;
        int expect =  7;
        assert(s.maxValue(input,2) == expect);
    }
}
