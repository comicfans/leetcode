#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() <4){
            return {};
        }
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> ret;

        int prevI = numeric_limits<int>::max();
        int prevJ = numeric_limits<int>::max();
        int prevK = numeric_limits<int>::max();

        for(int i = 0;i<nums.size()-3;++i){

            int thisI = nums[i];
            if(thisI==prevI){
                continue;
            }


            prevJ = numeric_limits<int>::max();

            for(int j = i+1; j<nums.size() - 2; ++ j){
                int thisJ = nums[j];
                if(thisJ == prevJ){
                    continue;
                }


                prevK = numeric_limits<int>::max();
                for(int k = j+1;k < nums.size()-1; ++k){
                    int thisK = nums[k];
                    if(thisK == prevK){
                        continue;
                    }


                    int64_t toFind = (int64_t)target - thisI - thisJ - thisK;
                    int cast = (int)toFind;
                    if(cast == toFind){
                        if(binary_search(nums.begin() + k + 1,nums.end(), cast)){
                            ret.push_back({thisI,thisJ,thisK,cast});
                        }
                    }

                    if(toFind <= thisK){
                        break;
                    }

                    prevK = thisK;

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
        vector<int> nums= {1,0,-1,0,-2,2};
        auto res = s.fourSum(nums, 0);
        for(auto p : res){
            for(auto c: p){
                cout<<c<<",";
            }
            cout<<endl;
        }
    }
    {
        vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
        s.fourSum(nums,0);
    }
}
