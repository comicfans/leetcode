#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {

        map<int,int> reachStep;
        reachStep[0] = 0;

        set<int> changed = {0};
        while(!reachStep.count(nums.size()-1)){

            set<int> nextChange ;
            for(auto idx: changed){

                for(int i =0;i< nums[idx];++i){

                    int reachIdx = idx + 1+i;
                    if(reachStep.count(reachIdx)){
                        continue;
                    }

                    nextChange.insert(reachIdx);
                    reachStep[reachIdx] = reachStep.at(idx) + 1;
                }

            }

            changed = nextChange;
        }

        return reachStep.at(nums.size()-1);
        
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {2,3,1,1,4};
        assert(s.jump(input) == 2);

    }
}
