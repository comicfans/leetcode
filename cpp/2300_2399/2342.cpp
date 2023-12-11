#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& nums) {

        map<int, vector<int>> catelogs;

        for(auto v: nums){

            int sum = 0;
            int copy = v;
            while(v>0){
                sum+= v%10;
                v/=10;
            }

            auto &big = catelogs[sum];
            big.push_back(copy);
            if(big.size() == 3){
                sort(big.begin(),big.end(),[](auto& lhs,auto& rhs){return lhs > rhs;});
                big.pop_back();
            }
        }

        int res = -1;
        for(auto & kv: catelogs){

            if(kv.second.size()<2){
                continue;
            }

            int thisRes = kv.second.front()+kv.second.back();
            res = max(thisRes, res);

        }
        return res;

        
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {229,398,269,317,420,464,491,218,439,153,482,169,411,93,147,50,347,210,251,366,401};
        auto res = s.maximumSum(input);
        assert(res == 973);
    }

}
