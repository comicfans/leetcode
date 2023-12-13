#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        set<int> noConflict;
        vector<int> search;

        int score = 0;

        for(int i = 0;i< scores.size();++i){

            bool hasConflict = false;
            for(int check = 0;check<scores.size();++check){

                if((ages[i] == ages[check]) || (scores[i] == scores[check])){
                    continue;
                }

                
                if((scores[i] > scores[check]) != (ages[i] > ages[check])){
                    hasConflict = true;
                    break;
                }
            }

            if(!hasConflict){
                score += scores[i];
            }else{
                search.push_back(i);
            }
        }



        vector<int> existing;
        int subRes = recFind(scores,ages,existing,search,0);
        return subRes + score;
    }

    int recFind(const vector<int>& scores,
                const vector<int>& ages,
                vector<int>& existing,
                vector<int>& search,
                int beginIdx){

        int subBest = 0;
        for(int idx = beginIdx;idx < search.size();++idx){
            auto p= search[idx];
            bool conflict =false;

            for(auto e: existing){

                if(ages[e] == ages[p] || scores[e] == scores[p]){
                    continue;
                }

                if((ages[e] > ages[p]) != (scores[e]>scores[p])){
                    conflict = true;
                    break;
                }

            }

            if(conflict){
                continue;
            }

            int thisSub = scores[p];
            existing.push_back(p);
            int subRes = recFind(scores,ages,existing,search,idx+1);
            existing.pop_back();

            subBest = max(subBest, thisSub + subRes);
        }

        return subBest;
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
