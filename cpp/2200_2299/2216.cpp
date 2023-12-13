#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minDeletion(vector<int>& nums) {

        int deleteNumber = 0;

        int pairLeft = -1;

        for(int i = 0; i< nums.size();++i){

            if((i + deleteNumber) % 2 == 0){
                pairLeft = nums[i];
            }else{
                if(nums[i] == pairLeft){
                    ++deleteNumber;
                    continue;
                }else{
                    pairLeft = -1;
                }
            }
        }

        if(pairLeft != -1){
            ++deleteNumber;
        }
        return deleteNumber;
    }
};
