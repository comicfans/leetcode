#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        if(nums.front() == nums.back()){
            return 0;
        }

        int current = 0;

        for(int shift = 1; shift < nums.size();++shift){

            int thisCount = 0;
            for(int i =0; i< nums.size();++i){

                if(nums[(i+shift) % nums.size()] > nums[i]){
                    ++thisCount;
                }
                else if(nums[(i+shift) % nums.size()] < nums[i]){
                    break;
                }
            }

            if(thisCount < current){
                return current;
            }else{
                current = thisCount;
            }
        }

        return current;
    }
};
