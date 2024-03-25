#include <cwchar>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;

        vector<int> chain;
        rec(nums,ret,chain, 0);

        return ret;
    }

    void rec(const vector<int>& nums, vector<vector<int>>& ret, vector<int>& chain, int pos){
        if(chain.size() >= 2){
            ret.push_back(chain);
        }

        if(pos == nums.size()){
            return;
        }

        

        int prev = (chain.empty()?-101:chain.back());

        set<int> tried ;
        for(int tryPos = pos; tryPos < nums.size(); ++tryPos){


            if(nums[tryPos]>= prev){

                if(tried.contains(nums[tryPos])){
                    continue;
                }

                tried.insert(nums[tryPos]);

                chain.push_back(nums[tryPos]);
                rec(nums,ret, chain, tryPos + 1);

                chain.pop_back();
            }

        }
    }
};

int main(){
    Solution s;
    {
        vector<int> nums = {4,6,7,7};
        vector<vector<int>> expect = {{4,6},{4,6,7},{4,6,7,7},{4,7},{4,7,7},{6,7},{6,7,7},{7,7}};
        auto res = s.findSubsequences(nums);
        sort(expect.begin(),expect.end());
        sort(res.begin(),res.end());
        assert(res == expect);
    }
}
