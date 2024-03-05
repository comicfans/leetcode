#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(),envelopes.end());

        vector<int> best(envelopes.size());


        return  rec(envelopes, 0, best,0,0, 0);
        
    }

    int rec(const vector<vector<int>>& envelopes, int beginSearch,vector<int>& best, int parentW,int parentH, int currentLength){

        if(beginSearch == envelopes.size()){
            return 0;
        }

        int useablePos = beginSearch;

            //find next useable

            while(useablePos < envelopes.size()){
                vector<int> nextV = {parentW+1,parentH+1};
                auto lower = lower_bound(envelopes.begin() + useablePos, envelopes.end(), nextV);

                if(lower  == envelopes.end()){
                    useablePos= envelopes.size();
                    break;
                }
                assert((*lower)[0]> parentW);

                if((*lower)[1] > parentH){
                    useablePos= lower - envelopes.begin();

                    assert(envelopes[useablePos][0]>parentW);
                    assert(envelopes[useablePos][1]>parentH);
                    break;
                }

                auto sameWidthEnd = lower_bound(lower+1, envelopes.end(), vector<int>{(*lower)[0]+1,0});


                auto bigger = lower_bound(lower, sameWidthEnd, vector<int>{(*lower)[0], parentH+1});

                if(bigger == sameWidthEnd){
                    useablePos= sameWidthEnd - envelopes.begin();
                    continue;
                }

                useablePos=bigger - envelopes.begin();

                assert(envelopes[useablePos][0]>parentW);
                assert(envelopes[useablePos][1]>parentH);
                break;
            }



        if(useablePos == envelopes.size()){
            return 0;
        }
        
        

        int useThisRes = best[useablePos];
        if(useThisRes==0){

            auto subRes = rec(envelopes, useablePos+1, best, envelopes[useablePos][0],envelopes[useablePos][1], currentLength+1);
            best[useablePos] = subRes+ 1;
            useThisRes = best[useablePos];
        }

        //find next  useable
        
        //because try same width bigger height is useless, so we should try
        //next width

        auto notUseThisRes = rec(envelopes,useablePos+1, best,envelopes[useablePos][0],parentH,  currentLength);

        return max(best[useablePos],notUseThisRes);

    }
};

#include "../parse.h"
int main(){

    Solution s;
    {

        auto env = pvvi("354_case.txt");
        int res = s.maxEnvelopes(env);

    }
    {
        vector<vector<int>> env = {{1,15},{7,18},{7,6},{7,100},{2,200},{17,30},{17,45},{3,5},{7,8},{3,6},{3,10},{7,20},{17,3},{17,45}};

        int res = s.maxEnvelopes(env) ;
        assert(res == 3);
    }
    {
vector<vector<int>> env = {{15,22},{8,34},{44,40},{9,17},{43,23},{4,7},{20,8},{30,46},{39,36},{45,14},{24,19},{24,36},{31,34},{32,19},{29,13},{16,48},{8,36},{44,2},{11,5},{2,50},{29,6},{18,38},{15,49},{22,37},{6,20},{25,11},{1,50},{19,40},{45,35},{37,21},{4,29},{40,5},{4,49},{1,45},{14,32},{14,37},{23,22},{31,21},{2,36},{43,4},{21,32},{41,2},{44,32},{36,20},{22,45},{3,41},{44,29},{29,33},{42,2},{38,17},{43,26},{30,15},{28,12},{33,30},{49,7},{8,14},{1,9},{41,25},{7,15},{26,32},{11,33},{12,45},{33,7},{16,34},{39,1},{20,49},{50,45},{14,29},{50,41},{1,45},{14,43},{49,20},{41,37},{43,22},{45,19},{20,21},{28,19},{2,1},{7,49},{3,3},{49,48},{34,35},{10,2}};
        int res = s.maxEnvelopes(env) ;
        assert(res == 16);
    }
    {
        vector<vector<int>> env = {{7,10},{14,7},{3,16},{6,3},{7,9},{5,2},{10,1},{6,11},{18,20}};
        int res = s.maxEnvelopes(env) ;
    }
    {
        vector<vector<int>> env = {{5,4},{6,4},{6,7},{2,3}};
        int res = s.maxEnvelopes(env) ;
        assert(res == 3);
    }
    {

        vector<vector<int>> env = {{1,1},{1,1},{1,1}};
        assert(s.maxEnvelopes(env) == 1);
    }
}
