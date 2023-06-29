#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        int last_1_pos = -1;
        uint64_t ret = 0;

        for(int i =0;i<nums.size();++i){

            if(nums[i]!=1){
                continue;
            }

            if (last_1_pos == -1){
                last_1_pos = i;
                ret = 1;
                continue;
            }

            auto not1_count_p1  = i-last_1_pos ;
            last_1_pos = i;
            if(not1_count_p1>1){
                ret = (ret * not1_count_p1) % 1000000007;
            }
            
        }

        return ret;
    }

    

};

int main(){
    Solution s;
    std::vector<int> nums = {0,1,0,0,1};
    assert(s.numberOfGoodSubarraySplits(nums) == 3);
    nums = {0,1,0};
    assert(s.numberOfGoodSubarraySplits(nums) == 1);


    nums = {0,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,1,0};

    assert(s.numberOfGoodSubarraySplits(nums) == 230630552);

    cout<<"ok"<<endl;
}
