#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {


        vector<int> res ={0};
        int currentSum = 0;
        for(int i = 0;i<nums.size();++i){

            currentSum += nums[i];
            if(currentSum >=res.back()){
                res.push_back(currentSum);
                currentSum = 0;
                continue;
            }
            //not big enough
        }

        if(currentSum >= res.back()){
            res.push_back(currentSum);
        }
        
        return res.size() - 1;
    }
};

int main(){
    Solution s;
    {
        vector<int> input= {5,2,2};
        assert(s.findMaximumLength(input)==1);
    }
    {
        vector<int> input = {272,482,115,925,983};
        assert(s.findMaximumLength(input)==4);
    }
}
