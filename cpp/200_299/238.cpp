#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums);

        for(int i = 1; i< left.size();++i){
            left[i] = left[i-1] * left[i];
        }


        vector<int> right(nums);
        for(int i = (int)right.size()-2;i>=0; --i){
            right[i] = right[i] * right[i+1];
        }

        vector<int> ret(nums.size());
        for(int i = 0; i< nums.size();++i){

            int leftProd = (i==0?1:left[i-1]);
            int rightProd = (i == nums.size()-1? 1: right[i+1]);

            ret[i] = leftProd * rightProd;

        }
        return ret;


        
    }
};
