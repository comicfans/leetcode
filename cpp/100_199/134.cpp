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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> delta (gas.size());

        for(int i = 0;i<gas.size();++i){
            delta[i] = gas[i] - cost[i];
        }

        int chainSum = 0;
        for(int j = 0;j < gas.size(); ++j){

            
            if(j!=0){
                chainSum -= delta[j-1];
            }

            for(int i=0;i<gas.size() && chainSum >= 0; ++i){
                
                chainSum += delta[(j + i) % gas.size()];

            }

            if(chainSum >= 0){
                return j;
            }
            

        }


        return -1;
    }
};

int main(){

    Solution s;
    {
        vector<int> gas= {5,1,2,3,4};
        vector<int> cost ={4,4,1,5,1};

        assert(s.canCompleteCircuit(gas,cost) == 4);
    }
    {
        vector<int> gas = {1,2,3,4,5};
        vector<int> station= {3,4,5,1,2};
        assert(s.canCompleteCircuit(gas,station) == 3);
    }
}
