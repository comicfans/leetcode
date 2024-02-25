#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums):cumsum(nums.size()) {

        
        for(int i =0;i<nums.size();++i){
            cumsum[i] = nums[i] + (i==0?0:cumsum[i-1]);
            
        }
        
    }
    
    int sumRange(int left, int right) {
        return cumsum[right] - (left>0?cumsum[left-1]:0);
    }

private: 
    vector<int> cumsum;
};
