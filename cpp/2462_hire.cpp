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

        map<int,set<int>> costPos;

        for(int i=0;i<costs.size();++i){
            costPos[costs[i]].insert(i);
        }


        long long total = 0;

        int leftPick = 0;
        int rightPick = 0;
        for(int i =0;i<k;++i){

            if(candidates >= costs.size() - leftPick - rightPick){

                //picking left k - i value from head

                int picked = 0;
                for(auto &kv: costPos){

                    int thisNumber = min((int)kv.second.size(), k-i - picked);
                    picked += thisNumber;
                    total += thisNumber * kv.first;
                    
                    if(picked == k - i){
                        break;
                    }
                }
                break;
            }




            for(auto it = costPos.begin();it!=costPos.end();){
                auto &posSet = it->second;

                //if any < candidates, or >= size - candidates
                //
                auto leftPos = posSet.begin();
                if(*leftPos < candidates + leftPick){
                    total += (int)(it->first);
                    posSet.erase(leftPos);
                    ++leftPick;
                    if(posSet.empty()){
                        auto erase = it;
                        ++it;
                        costPos.erase(erase);
                        break;
                    }else{
                        ++it;
                        break;
                    }
                }
                //not in left set
                
                auto rightPos = posSet.lower_bound(costs.size()- rightPick - candidates);
                if((rightPos != posSet.end()) || (*rightPos > costs.size()- rightPick - candidates)){
                    total+= (long long )(it->first);
                    posSet.erase(rightPos);
                    ++rightPick;
                    if(posSet.empty()){
                        auto erase = it;
                        ++it;
                        costPos.erase(erase);
                        break;
                    }else{
                        ++it;
                        break;
                    }
                }
                ++it;
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
}
