#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> appear(nums.size(),0);
        
        for(auto v: nums){
            appear[v-1] = 1;
        }
        int currentPos = 0;
        for(int i = 0; i< nums.size(); ++i){
            if(appear[i]==0){
                appear[currentPos] = i + 1;
                ++currentPos;
                continue;
            }
        }
        appear.resize(currentPos);
        return appear;
    }
};
