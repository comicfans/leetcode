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
    NumArray(vector<int>& nums):copy(nums) {
        
    }
    
    int sumRange(int left, int right) {

        return accumulate(copy.begin()+left, copy.begin()+right+1,0);
    }

private: 
    vector<int> copy;
};
