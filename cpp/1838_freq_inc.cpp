#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int currentBest = 0;

        map<int, int> from_consume;
        from_consume[-1] = 0;

        for(int target = 0; target < nums.size(); ++target){

            for(auto& kv: from_consume){

                //from from to target
                //
                //
                //
                //      
                //      
                //                                 -------------
                //                                |
                //                                |
                //                                |
                //                                |
                //                                |
                //                                |
                //                 ---------------
                //                |
                //                |
                //                |
                // ---------------
                //
                // how much do we need to fill additional gap ?
                int delta = (target == 0 ? nums[target]: nums[target] - nums[target-1]);

                if(delta == 0){
                    continue;
                }

            }
        }


        
    }
};
