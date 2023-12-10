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

        sort(events.begin(),events.end());
        map<int, map<int,int>> cache;

        return recFind(events,k,-1,0,cache);
    }

    int recFind(const vector<vector<int>>& events, int k,int prevEnd, int beginIdx, map<int,map<int,int>>& cache){
        if(k == 0){
            return 0;
        }

        //pick any possible

        int thisBest = 0;

        int tryBegin = 0;
        if(prevEnd != -1){

            auto searchBegin = upper_bound(events.begin()+ beginIdx,events.end(),vector<int>{prevEnd},[](auto& lhs,auto& rhs ){
                return lhs[0] < rhs[0];
            });
            tryBegin = searchBegin - events.begin();
        }

        for(int tryIdx = tryBegin; tryIdx < events.size(); ++ tryIdx){

            auto& ev = events[tryIdx];


            int thisRes = 0;
            bool hasCache = false;
            auto cachePos = cache.find(tryIdx);
            if(cachePos != cache.end()){
                auto kPos = cachePos->second.find(k);
                if(kPos != cachePos->second.end()){
                    hasCache = true;
                    thisRes = kPos->second;
                }
            }

            if(!hasCache){
                int subRes = recFind(events, k-1, ev[1] ,tryIdx + 1,cache);
                thisRes = ev[2] + subRes;
                cache[tryIdx][k] = thisRes;
            }

            
            thisBest = max(thisRes, thisBest);
        }
        return thisBest;
    }
};

#include "parse.h"
int main(){
    Solution s;
    {
        auto input = pvvi("1751_case1.txt", 1);
        int k = 50;
        s.maxValue(input,k);
    }
    {
        auto input = pvvi("1751_case1.txt", 0);
        int k = 50;
        s.maxValue(input,k);
    }
    {
        vector<vector<int>> input= {{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
        int k = 3;
        int expect =  9;
        assert(s.maxValue(input,k) == expect);

    }
    {

        vector<vector<int>> input= {{1,2,4},{3,4,3},{2,3,1}};
        int k = 2;
        int expect =  7;
        assert(s.maxValue(input,2) == expect);
    }
}
