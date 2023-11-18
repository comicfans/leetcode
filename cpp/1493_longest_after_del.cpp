#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        vector<pair<int,int>> rle;

        for(auto v: nums){
            if(rle.empty() || (v!= rle.back().first)){
                rle.push_back({v,1});
            }else{
                rle.back().second++;
            }

        }


        //removing only possible between longest1 pos and its siberlings

        int bestOfAll = 0;
        for(int onePos = 0; onePos < rle.size();++onePos){
            if(rle[onePos].first==0){
                continue;
            }

            //try remove left only if left has  1 zero

            int currentBest = -1;
            if(onePos > 0){
                //try merge left part
                //has left 0
                if (rle[onePos-1].second>1){
                    //after removing left zero, still not connect to 1
                    currentBest = rle[onePos].second;
                }else{
                    //only 1 zero
                    if (onePos >= 2){
                        currentBest = rle[onePos].second+ rle[onePos-2].second;
                    }else{
                        currentBest = rle[onePos].second;
                    }
                }
            }else{
                //remove 1 from this segment
                currentBest = max(currentBest, rle[onePos].second - 1);
            }


            if(onePos >= (int)rle.size() - 2){
                if(onePos < (int)rle.size()-1){
                    //has right zero
                    currentBest = max(currentBest, rle[onePos].second);
                }

                if((onePos < (int)rle.size()-2)&& (rle[onePos+1].second == 1)){
                    int mergeRight = rle[onePos].second + rle[onePos+2].second;

                    currentBest = max(currentBest, mergeRight);
                }
            }
            bestOfAll = max(bestOfAll, currentBest);
        }
        
        return bestOfAll;
    }
};

int main(){
    Solution s;
    {
        vector<int> seq = {1,1,0,1};
        assert(s.longestSubarray(seq)== 3);
    }
    {
        vector<int> seq = {0,1,1,1,0,1,1,0,1};
        assert(s.longestSubarray(seq)== 5);
    }
    {
        vector<int> seq = {1,1,1};
        assert(s.longestSubarray(seq)== 2);
    }
    {
        vector<int>seq = {1,0,0,0,0};
        assert(s.longestSubarray(seq)== 1);
    }
    {

        vector<int>seq = {0,0,1,1};
        assert(s.longestSubarray(seq)== 2);
    }
    {
        vector<int>seq = {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1};
        assert(s.longestSubarray(seq)== 18);
    }
    {
        vector<int>seq = {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,0,1,1,1,1};
        assert(s.longestSubarray(seq)== 14);
    }
}
