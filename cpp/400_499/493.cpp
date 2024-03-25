#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {

        vector<pair<int,int>> minCount;

        auto lambda = [](const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.first < rhs.first;
        };


        int ret = 0;
        for(int idx = 0; idx < nums.size(); ++idx){
            const auto v = nums[idx];
            auto pos = lower_bound(minCount.begin(), minCount.end(),pair<int,int>{v,v}, lambda);

            if(pos != minCount.end()){
                ret += pos->second;
            }


            //3 -> 1
            //2 -> 0
            //
            //0 -> -1
            //-1 -> -1
            //-2 -> -2
            //-3 -> -2
            //-4 -> -3
            //-5 -> -3
            int half = v> 0? (v-1)/2 : (int)round((double)v/2 - 0.5);

            auto insPos = lower_bound(minCount.begin(), minCount.end(), pair<int,int>{half,half},lambda);

            int offset = insPos - minCount.begin();
            int end = offset;
            if(insPos == minCount.end() || insPos->first != half){
                if(offset <minCount.size()){
                    minCount.insert(insPos, {half, minCount[offset].second + 1});
                }else{
                    minCount.insert(insPos, {half, 1});
                }
            }else{
                ++end;
            }

            for(int i = 0; i< end; ++i){
                minCount[i].second ++;
            }
            
        }

        return ret;
    }

    int reversePairs3(vector<int>& nums) {

        vector<pair<int,int>> minCount;

        auto lambda = [](const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.first < rhs.first;
        };


        int ret = 0;
        for(auto v: nums){

            auto pos = lower_bound(minCount.begin(), minCount.end(),pair<int,int>{v,v}, lambda);

            for(auto it = pos ; it != minCount.end(); ++it){
                ret += it->second;
            }

            //3 -> 1
            //2 -> 0
            int half = v> 0? (v-1)/2 : (int)round((double)v/2 - 0.5);
            auto insPos = lower_bound(minCount.begin(), minCount.end(), pair<int,int>{half,half},lambda);

            if(insPos == minCount.end() || insPos->first != half){
                minCount.insert(insPos, {half,1});
            }else{
                insPos->second ++;
            }
        }

        return ret;
    }

    int reversePairs2(vector<int>& nums) {

        map<double,int> minCount;

        int ret = 0;
        for(int idx = 0;idx < nums.size(); ++idx){
            const auto v =  nums[idx];
            auto pos = minCount.upper_bound(v);

            for(auto it = pos ; it != minCount.end(); ++it){
                ret += it->second;
            }

            double half = (double)v / 2;

            minCount[half]++;
        }

        return ret;
    }
};

#ifdef LEETCODE 

#include "../parse.h"
int main(){
    Solution s;
    {

        VI nums = {-5,-5};

            auto res2 = s.reversePairs2(nums);
            auto res1 = s.reversePairs(nums);
            auto res3 = s.reversePairs3(nums);
            assert(res1 == res2);
            assert(res1 == res3);

    }
    {

        auto nums = pvi("493_case.txt", 1);
        for(int i = 5; i< 1000; ++i){

            auto copy = nums;

            copy.resize(i);
            auto res3 = s.reversePairs3(copy);
            auto res2 = s.reversePairs2(copy);
            auto res1 = s.reversePairs(copy);
            assert(res1 == res2);
            assert(res1 == res3);

       }

    }
    {
        vector<int> nums = {1,3,2,3,1};

        auto res = s.reversePairs(nums);

        assert(res == 2);
    }
    
    {

        auto nums = pvi("493_case.txt", 0);
        auto res = s.reversePairs(nums);
    }
    

}

#endif
