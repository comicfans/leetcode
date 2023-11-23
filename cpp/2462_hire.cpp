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

        vector<pair<int,int>> possible;

        for(int hire=0; hire <k; ++hire){

            

            if(hire == 0){
                for(int i = 0;i< candidates;++i){
                    possible.push_back({costs[i],0});
                }

                for(int i=0; i< min<int>(candidates, costs.size() - candidates);++i){
                    possible.push_back({costs[costs.size()-1-i],1});
                }
                sort(possible.begin(),possible.end(),[](auto lhs, auto rhs){return lhs > rhs;});
                
            }

            if(end - begin <= candidates * 2){
                //left ones can be merged together
                for(int i = 0;i< k - hire; ++i){
                    total += possible[possible.size()-1-i].first;
                }
                break;
            }

            pair<int,int> minElement = possible.back();
            total += minElement.first;
            possible.pop_back();
            pair<int,int> newAdd;
            if(minElement.second == 0){
                ++begin;
                newAdd = {costs[begin + candidates -1],0};
            }else{
                --end;
                newAdd = {costs[end - candidates],1};
            }

            auto insertPos = upper_bound(possible.begin(),possible.end(),newAdd, [](auto lhs,auto rhs){return lhs>rhs;});

            possible.insert(insertPos, newAdd);
 
            //vector<int> copy;
            //transform(possible.begin(),possible.end(),back_inserter(copy),[](auto& v){return v.first;});
            //sort(copy.begin(),copy.end(),[](auto lhs, auto rhs){return lhs > rhs;});
            //for(int i =0;i< copy.size();++i){
            //    assert(copy[i] == possible[i].first);
            //}

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
        vector<int> costs= {31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
        int k = 11;
        int candidates = 2;
        assert(s.totalCost(costs,k,candidates) == 423);
    }
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
