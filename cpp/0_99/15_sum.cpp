#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> ret;

        int prevI = numeric_limits<int>::min();

        for(int i = 0;i<nums.size()-2;++i){

            int thisI = nums[i];
            if(thisI==prevI){
                continue;
            }

            int prevJ = numeric_limits<int>::min();

            for(int j = i+1; j<nums.size() - 1; ++ j){
                int thisJ = nums[j];
                if(thisJ == prevJ){
                    continue;
                }

                int toFind = 0 - thisI - thisJ;

                if(binary_search(nums.begin() + j + 1,nums.end(), toFind)){
                    ret.push_back({thisI,thisJ,toFind});
                }

                if(toFind <= thisJ){
                    break;
                }
                

                prevJ = nums[j];
            }

            prevI = nums[i];
        }

        return ret;
    }
};

int main(){

    Solution s;
    {
        vector<int> nums= {-1,0,1,2,-1,-4};
        s.threeSum(nums);
    }
}
