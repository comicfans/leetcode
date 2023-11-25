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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int allSum = accumulate(nums.begin(),nums.end(), 0);

        vector<int> res;
        res.resize(nums.size());

        int leftSum = 0;

        for(int i = 0;i< nums.size();++i){

            leftSum += nums[i];
            int rightSum = allSum - leftSum;

            res[i] = abs(nums[i]* (i+1)-leftSum)+ abs(nums[i]*(int)(nums.size()-i-1)-rightSum);
        }

        return res;
        
    }
};
