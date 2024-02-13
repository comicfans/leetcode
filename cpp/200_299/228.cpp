#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;

        if(nums.empty()){
            return {};
        }
        int prevBegin = nums.front();
        int prevEnd = nums.front();

        for(int pos = 1; pos < nums.size();++pos){
            if(nums[pos] == prevEnd+1){
                prevEnd = nums[pos];
                continue;
            }

            if(prevEnd == prevBegin){
                ret.push_back(to_string(prevBegin));
                
            }else{
                ret.push_back(to_string(prevBegin) + "->" + to_string(prevEnd));
            }

            prevBegin = nums[pos];
            prevEnd = nums[pos];
        }


            if(prevEnd == prevBegin){
                ret.push_back(to_string(prevBegin));
                
            }else{
                ret.push_back(to_string(prevBegin) + "->" + to_string(prevEnd));
            }

        return ret;
    }
};
