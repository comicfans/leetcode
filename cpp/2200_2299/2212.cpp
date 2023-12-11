#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
        int bestScore = 0;

        vector<int> currentBest ;

        vector<int> existing;
        recFind(numArrows, aliceArrows, existing, 0, bestScore,currentBest);

        int sum = accumulate(currentBest.begin(),currentBest.end(), 0);

        int left = numArrows - sum;
        currentBest[0] += left;

        return currentBest;
    }

    void recFind(const int numArrows, const vector<int>& aliceArrows, vector<int>& existing,int existingScore, int& bestScore, vector<int>& bestPick){

        if(existing.size() == aliceArrows.size()){
            if(existingScore > bestScore){
                bestScore = existingScore;
                bestPick = existing;
            }

            return;
        }

        //for round 
        int score = existing.size();
        //pick 0, or alice +1

        existing.push_back(0);
        recFind(numArrows, aliceArrows, existing, existingScore, bestScore, bestPick);
        existing.pop_back();

        //try to alice + 1

        int consume = aliceArrows[existing.size()]+1;
        if(consume > numArrows){
            return;
        }

        existing.push_back(consume);
        recFind(numArrows - consume, aliceArrows,existing, existingScore + score, bestScore, bestPick);
        existing.pop_back();
    }
};

int main(){
    Solution s;
    {
        int numArrows = 89;
        vector<int> aliceArrows = {3,2,28,1,7,1,16,7,3,13,3,5};
        auto res = s.maximumBobPoints(numArrows, aliceArrows);
        int b=4;
    }
    {
        int numArrows = 3; 
        vector<int> aliceArrows = {0,0,1,0,0,0,0,0,0,0,0,2};
        vector<int> expect = {0,0,0,0,0,0,0,0,1,1,1,0};
        auto res = s.maximumBobPoints(numArrows, aliceArrows);
        assert(res == expect);
    }
    {
        int numArrows = 9;
        vector<int> aliceArrows = {1,1,0,1,0,0,2,1,0,1,2,0};
        vector<int> expect =  {0,0,0,0,1,1,0,0,1,2,3,1};
        auto res = s.maximumBobPoints(numArrows,aliceArrows);
        assert(res == expect);
    }
    
}
