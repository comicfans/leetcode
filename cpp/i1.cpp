#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {

        int ret = 0;
        for(int i = 0;i<batteryPercentages.size();++i){

            if(batteryPercentages[i]>0){
                ++ret;
                for(int j = i+1;j<batteryPercentages.size();++j){
                    batteryPercentages[j] = max(batteryPercentages[j]-1,0);

                }
            }

        }
        return ret;
        
    }
};
