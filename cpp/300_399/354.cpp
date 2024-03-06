#include <iostream>
#include <iterator>
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

        vector<pair<int,int>> prePost(envelopes.size());

        int globalBest = 0;
        for(int i = 0;i < envelopes.size(); ++i){
            if(prePost[i].first!=0){
                continue;
            }
            rec(envelopes, prePost, i , 0, 0,0,globalBest);
            globalBest = max(globalBest, prePost[i].first + prePost[i].second);
        }

            
        int ret = 0;
        for(const auto& v:prePost){
            ret = max(ret, v.second + v.first);
        }

        return ret;

        
    }



    int rec(const vector<vector<int>>& envelopes, 
             vector<pair<int,int>>& prePost,
             int beginSearch,
             int parentW,int parentH, int currentLength, int& globalBest){


            //find next useable

        int useablePos = beginSearch;
        int subMax = 0;
        int prevW = parentW;
            while(useablePos < envelopes.size()){
                vector<int> nextV = {prevW+1,parentH+1};
                auto wBigger = lower_bound(envelopes.begin() + useablePos, envelopes.end(), nextV) - envelopes.begin();

                if(wBigger == envelopes.size()){
                    break;
                }

                //assert(envelopes[wBigger][0]> prevW);


                auto hBigger = lower_bound(envelopes.begin()+wBigger, envelopes.end(),
                                          vector<int>{envelopes[wBigger][0], parentH+1}) - envelopes.begin();

                if(hBigger == envelopes.size()){
                    break;
                }

                bool stopTry= false;
                for(useablePos = hBigger;useablePos < envelopes.size(); ++useablePos){

                    if(envelopes.size() - useablePos + currentLength <= globalBest){
                    //stopTry = true;
                    break;
                }

                        //assert(envelopes[useablePos][0]> prevW);
                        if(envelopes[useablePos][1]<=parentH){
                            prevW =envelopes[hBigger][0]-1;
                            ++useablePos;
                            break;
                    }

                    if(prePost[useablePos].second > 0){
                        
                        prePost[useablePos].first = max(prePost[useablePos].first, currentLength);
                        subMax = max(subMax, prePost[useablePos].second);
                        globalBest = max(globalBest, subMax + currentLength);
                        continue;
                    }

                    //assert(prePost[useablePos].first == 0);
                    prePost[useablePos].first = currentLength;
                    prePost[useablePos].second = rec(envelopes, prePost, useablePos+1, envelopes[useablePos][0], envelopes[useablePos][1], currentLength+1,globalBest)+1;
                    subMax = max(subMax, prePost[useablePos].second);
                }
                
            if(stopTry){
                break;
            }
            }
        return subMax;
    }



};

#include "../parse.h"
int main(){

    Solution s;
    {

        vector<vector<int>> env = {{1,1},{1,1},{1,1}};
        assert(s.maxEnvelopes(env) == 1);
    }
    
    
    {
        vector<vector<int>> env = {{1,15},{7,18},{7,6},{7,100},{2,200},{17,30},{17,45},{3,5},{7,8},{3,6},{3,10},{7,20},{17,3},{17,45}};

        int res = s.maxEnvelopes(env) ;
        assert(res == 3);
    }
    {
    vector<vector<int>> env = {{15,22},{8,34},{44,40},{9,17},{43,23},{4,7},{20,8},{30,46},{39,36},{45,14},{24,19},{24,36},{31,34},{32,19},{29,13},{16,48},{8,36},{44,2},{11,5},{2,50},{29,6},{18,38},{15,49},{22,37},{6,20},{25,11},{1,50},{19,40},{45,35},{37,21},{4,29},{40,5},{4,49},{1,45},{14,32},{14,37},{23,22},{31,21},{2,36},{43,4},{21,32},{41,2},{44,32},{36,20},{22,45},{3,41},{44,29},{29,33},{42,2},{38,17},{43,26},{30,15},{28,12},{33,30},{49,7},{8,14},{1,9},{41,25},{7,15},{26,32},{11,33},{12,45},{33,7},{16,34},{39,1},{20,49},{50,45},{14,29},{50,41},{1,45},{14,43},{49,20},{41,37},{43,22},{45,19},{20,21},{28,19},{2,1},{7,49},{3,3},{49,48},{34,35},{10,2}};

        //(2,1)(3,3)(4,7)(20,8)(25,11)(28,12)(29,13)(30,15)(32,19)(36,20)(37,21)(41,25)(43,26)(44,29)(45,35)(49,48)

        //int res2 = s.maxEnvelopes2(env) ;
        int res = s.maxEnvelopes(env) ;
        assert(res == 16);
    }
    {
        vector<vector<int>> env = {{7,10},{14,7},{3,16},{6,3},{7,9},{5,2},{10,1},{6,11},{18,20}};
        int res = s.maxEnvelopes(env) ;
        //int res2= s.maxEnvelopes2(env);
        assert(res == 4);
    }
    {
        vector<vector<int>> env = {{5,4},{6,4},{6,7},{2,3}};
        int res = s.maxEnvelopes(env) ;
        assert(res == 3);
    }
    {

        auto env = pvvi("354_case.txt",0);
        int res = s.maxEnvelopes(env);
        cout<<"0:"<<res<<endl;

    }
    {

        auto env = pvvi("354_case.txt",1);
        int res = s.maxEnvelopes(env);
        cout<<"1:"<<res<<endl;

    }
}
