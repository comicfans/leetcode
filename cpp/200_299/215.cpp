#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        vector<int> maxV;

        for(auto v:nums){
            auto insPos = lower_bound(maxV.begin(),maxV.end(),v) - maxV.begin();
            if(insPos == maxV.size()){
                if(maxV.size() == k){
                    maxV.erase(maxV.begin());
                }
                maxV.push_back(v);
                continue;
            }

            if(maxV.size() != k){
                maxV.insert(maxV.begin()+insPos, v);
                continue;
            }


            if(insPos == 0){
                continue;
            }

            --insPos;
            maxV.erase(maxV.begin());

            

            maxV.insert(maxV.begin()+insPos, v);
        }

        
        return maxV.front();
    }
};
int main(){
    Solution s;
    {
        vector<int> nums= {-1,2,0};
        int k = 3;
        assert(s.findKthLargest(nums,k)==-1);
    }
    {
        vector<int> nums={3,2,3,1,2,4,5,5,6};
        int k = 4;
        assert(s.findKthLargest(nums,k) == 4);
    }
    {
        vector<int> nums = {3,2,1,5,6,4};
        auto res = s.findKthLargest(nums,2);
        assert(res == 5);
    }
}
