#include <limits>
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

    long long totalCost(vector<int>& costs, int k, int candidates) {

        if(costs.size() == k){
            //
            return accumulate(costs.begin(),costs.end(),(long long)0);
        }


        int begin = 0;

        int end = costs.size();

        long long total = 0;
        for(int hire=0; hire <k;){

            if(costs.size()-hire <= candidates * 2){
                //left ones can be merged together
                sort(costs.begin()+begin,costs.begin()+end);
                total += accumulate(costs.begin()+begin,costs.begin()+begin + k-hire, (long long)0);
                break;
            }

            if(hire == 0){
                sort(costs.begin(),costs.begin()+ candidates);
                sort(costs.end() - candidates, costs.end(),[](auto lhs,auto rhs){
                return lhs > rhs;
                });
            }

            if(costs[begin] <= costs[end - 1]){

                if(costs[begin] == 1){
                    //pick as many as possible because this is min value
                    auto end = upper_bound(costs.begin()+begin,costs.begin() + begin + candidates, 1);
                    auto consume = min<int>(end - (costs.begin()+begin), k - hire);
                    total += consume;
                    begin += consume;
                    hire += consume;
                    sort(costs.begin()+begin, costs.begin()+begin+candidates);
                    continue;
                }


                ++hire;
                total+=costs[begin];
                ++begin;
                //pick left first
                if(candidates==1){
                    continue;
                }
                    
                int newAdd = costs[begin+candidates-1];
                if(newAdd<costs[begin]){
                    copy(costs.begin()+begin,costs.begin()+begin+candidates-1, costs.begin()+begin+1);
                    costs[begin] = newAdd;
                }else{
                    sort(costs.begin()+begin,costs.begin()+begin + candidates);
                }

                continue;
            }

            if(costs[end - 1] == 1){
                auto lowerBound = lower_bound(costs.begin()+end - candidates, costs.begin()+end,1, [](auto lhs,auto rhs){
                    return lhs>rhs;
                });
                auto same = costs.begin()+end - lowerBound;
                int consume = min<int>(same, k-hire);
                total += consume;
                end -= consume;
                hire += consume;

                sort(costs.begin() + end - candidates, costs.begin()+end, [](auto lhs,auto rhs){
                    return lhs > rhs;
                });
                continue;
            }

            ++hire;
            total+=costs[end - 1];
            --end;
            if(candidates>1){
                int newAdd = costs[end - candidates];
                if(newAdd < costs[end]){
                    copy(costs.begin()+end - candidates+1, costs.begin()+end, costs.begin()+end - candidates);
                    costs[end - 1] = newAdd;
                }else{
                    sort(costs.begin() + end - candidates, costs.begin() + end,[](auto lhs,auto rhs){return lhs > rhs;});
                }
            }
        }
        

        return total;
    }


    long long slow(vector<int>& costs, int k, int candidates) {

        long long ret = 0;
        for(int i=0;i< k; ++i){

            int leftIdx = 0;
            int minCost = numeric_limits<int>::max();

            int rightIdx = costs.size()-1;
            int minCostRight = minCost;

            for(int i=0;i<min(candidates, (int)costs.size());++i){
                if(costs[i]<minCost){
                    leftIdx = i;
                    minCost = costs[i];
                }

                if(costs[costs.size()-1 - i]< minCostRight){
                    minCostRight = costs[costs.size()-1 - i];
                    rightIdx = costs.size()-1-i;
                }
            }

            int erasePos = minCostRight == minCost? min(leftIdx,rightIdx): (minCostRight < minCost? rightIdx: leftIdx);

            ret += costs[erasePos];

            copy(costs.begin()+erasePos+1, costs.end(), costs.begin()+erasePos);
            costs.resize(costs.size()-1);
        }

        return ret;

        
    }
};

#include "parse.h"

int main(){
    Solution s;
    {
        vector<int> costs = {17,12,10,2,7,2,11,20,8};
        int k = 3;
        int candidates = 4;
        assert(s.totalCost(costs, k,candidates) == 11);
    }
    {
        vector<int> costs = {3,2,7,7,1,2};
        int k = 2;
        int candidates = 2;
        assert(s.totalCost(costs, k,candidates) == 3);
    }
    {
        vector<int> costs = {1,2,4,1};
        int k = 3;
        int candidates = 3;
        assert(s.totalCost(costs, k,candidates) == 4);
    }
    {
        vector<int> costs = {19,29,88,2,5,24,60,26,76,24,96,82,97,97,72,35,21,77,82,30,94,55,76,94,51,82,3,89,52,96,72,27,59,57,97,6,46,88,41,52,46,4,17};
        int k = 1;
        int candidates = 3;
        assert(s.totalCost(costs,k,candidates) == 4);
    }
    {
        vector<int> costs= {50,80,34,9,86,20,67,94,65,82,40,79,74,92,84,37,19,16,85,20,79,25,89,55,67,84,3,79,38,16,44,2,54,58};
        int k = 7;
        int candidates = 12;
        assert(s.totalCost(costs,k,candidates) == 95);

    }
    {
        auto costs = pvi("2462_hire.case1",0);
        int k = 52220;
        int candidates = 725;
        s.totalCost(costs, k ,candidates);

    }
    {
        auto costs = pvi("2462_hire.case2",0);
        int k = 60000;
        int candidates = 20000;
        s.totalCost(costs, k ,candidates);

    }
}
