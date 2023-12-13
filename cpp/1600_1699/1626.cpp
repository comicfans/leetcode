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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int,int>> score_ages(scores.size());
        for(int i = 0;i < scores.size();++i ){
            score_ages[i].first = scores[i];
            score_ages[i].second = ages[i];
        }

        sort(score_ages.begin(),score_ages.end());

        //remove minimum score element, to make it non-decreasing

        int totalScore = accumulate(scores.begin(),scores.end(),0);

        pair<int,int> prev = {0,0};

        vector<int> cache(scores.size(),-1);
        return recFind(score_ages,0,prev,cache);

    }

    int recFind(const vector<pair<int,int>>& score_ages, const int beginSearch, 
                const pair<int,int> prev,vector<int>& cache){

        if(beginSearch == score_ages.size()){
            return 0;
        }

        int fromThisScore = 0;

        for(int i = beginSearch;i < score_ages.size(); ++i){
            auto p = score_ages[i];
            if(p.first > prev.first && p.second < prev.second){
                //this can't be used
                continue;
            }

            // this can be used, may choose it or not
            if(cache[i]==-1){

                int chooseThisScore = p.first;
                {
                    int subRes = recFind(score_ages, i+1, p, cache);
                    chooseThisScore += subRes;
                }

                int notChooseThisScore =recFind(score_ages, i+1, prev,cache);

                cache[i] = max(chooseThisScore, notChooseThisScore);
            }

            fromThisScore = max(fromThisScore, cache[i]);
        }

        return fromThisScore;
    }
};

int main(){
    Solution s;
    {
        vector<int> scores = {4,5,6,5};
        vector<int> ages = {2,1,2,1};
        int expect= 16;
        auto res = s.bestTeamScore(scores,ages);
        assert(res == expect);
    }
    {
        vector<int> scores = {1,3,5,10,15};
        vector<int> ages = {1,2,3,4,5};
        auto res = s.bestTeamScore(scores,ages);
        assert(res == 34);
    }
}
