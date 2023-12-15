#include <cmath>
#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {


        sort(cuts.begin(),cuts.end());

        return recCut(0,n,cuts, 0 , cuts.size());

    }

    int recCut(int base, int n,const vector<int>& cuts, int begin, int end){

        int cutSize = end - begin;
        if(cutSize == 0){
            return 0;
        }

        int length = n - base;
        if(cutSize == 1){
            return length;
        }


        int thisSpend = length;

        float halfSize = (float)length / 2 + base;


        auto tryPos = lower_bound(cuts.begin() + begin, cuts.begin() + end, halfSize) - cuts.begin() ;

        float thisDiff = fabs(halfSize - cuts[tryPos]);
        vector<int> bestPos = {(int)tryPos};
        for(auto test : {-1,1}){
            int testPos = tryPos + test;
            if(testPos <0 || testPos >= cuts.size()){
                continue;
            }

            float testDiff = fabs(cuts[testPos] - halfSize);
            if(testDiff < thisDiff){
                thisDiff = fabs(cuts[testPos] - halfSize);
                bestPos = {(int)testPos};
            }else if(testDiff == thisDiff){
                bestPos.push_back(testPos);
            }
        }



        int thisBest = numeric_limits<int>::max();

        for(int i = 0; i< bestPos.size(); ++i){
            int cutPos = bestPos[i];

            int cutAt = cuts[cutPos];

            int leftCut = recCut(base, cutAt, cuts, begin, cutPos);
            int rightCut = recCut(cutAt,n, cuts, cutPos + 1,end);
            int thisRes = thisSpend + leftCut + rightCut;
            thisBest = min(thisBest, thisRes);
        }

        return thisBest;
    }
};

int main(){

    Solution s;
    {
        vector<int> cuts = {1,3,4,5};
        assert(s.minCost(7,cuts) == 16);
    }
    {
        vector<int> cuts  ={13,6,7,2,10};
        assert(s.minCost(20,cuts) == 50);

    }
}
