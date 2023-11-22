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


        vector<pair<int,int>> numberIdx;
        numberIdx.resize(costs.size());
        for(int i = 0;i<costs.size();++i){
            numberIdx[i].first = costs[i];
            numberIdx[i].second = i;
        }

        sort(numberIdx.begin(), numberIdx.end(), [](auto lhs, auto rhs){
            return lhs > rhs;
        });

        //search from back
        //
        int leftPick = 0;
        int rightPick = 0;
        long long total = 0;

        for(int i = 0; i< k;++i){
            if(numberIdx.size() <= candidates){
                for(int j= 0;j< k-i;++j){
                    total+= numberIdx[numberIdx.size()-1 - j].first;
                }
                break;
            }


            //search from right to left, find first element which second is < can + leftPick
            //or >= size - candidates - rightPick

            for(int idx = numberIdx.size()-1;idx>=0; --idx){
                bool found = false;
                if(numberIdx[idx].second < candidates + leftPick){
                    found = true;
                    ++leftPick;
                } else if(numberIdx[idx].second >= costs.size() - rightPick - candidates){
                    found = true;
                    ++rightPick;
                }

                if(found){
                    total+= numberIdx[idx].first;
                    copy(numberIdx.begin()+idx+1, numberIdx.end(), numberIdx.begin()+idx);
                    numberIdx.pop_back();
                    break;
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
}
