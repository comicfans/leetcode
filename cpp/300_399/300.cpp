#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        map<int,int> numLength;

        int ret = 0;
        for(int i = 0;i<nums.size();++i){
            int v = nums[i];

            int currentLength = 0;
            auto pos = numLength.begin();
            for(;pos != numLength.end();++pos){

                if(pos->first >= v){
                    break;
                }

                currentLength = max(currentLength, pos->second);
            }

            ret = max(currentLength+1, ret);
            if(pos == numLength.end() || pos->first != v){
                numLength.insert(numLength.end(), {v, currentLength+1});
                continue;
            }

            pos->second = max(pos->second, currentLength + 1);
        }
        
        return ret;
    }
};
