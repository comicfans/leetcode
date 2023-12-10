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
        rle.reserve(4);

        auto findBest= [&](){
            if(rle.size()==0){
                return 0;
            }

            if(rle.size()==1){
                return rle.front().first ==0? 0: rle.front().second-1;
            }

            if(rle.size()==2){
                return rle.front().first ==1? rle.front().second: rle.back().second;
            }

            int onePos = find_if(rle.begin(),rle.end(),[](const auto& v){
                return v.first == 1;
            }) - rle.begin();

            int ret = rle[onePos].second;
            if (onePos +2 < rle.size()){
                ret = rle[onePos+1].second == 1? rle[onePos].second + rle[onePos+2].second:
                            max(rle[onePos].second, rle[onePos+2].second);
            }
            if(rle.size() == 4){
                copy(rle.begin()+2,rle.end(), rle.begin());
                rle.resize(2);
            }


            return ret;
        };

        int bestOfAll = 0;

        for(auto v: nums){
            if(rle.empty()){
                rle.push_back({v,1});
                continue;
            }


            if(rle.back().first != v){
                if(rle.size() == 4){
                    int thisBest = findBest();
                    bestOfAll = max(bestOfAll, thisBest);
                }
                rle.push_back({v,1});

            }else{
                rle.back().second++;
            }
        }

        int leftBest = findBest();
        
        return max(bestOfAll,leftBest);
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
