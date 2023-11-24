#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<vector<int>> ret;

        int nums1Idx = 0;
        int nums2Idx = 0;

        while(ret.size()< k){
            ret.push_back({nums1[nums1Idx], nums2[nums2Idx]});
            
            if(nums1Idx == nums1.size()-1){
                if(nums2Idx == nums2.size() -1){
                    break;
                }else{
                    nums2Idx++;
                    nums1Idx = 0;
                    continue;
                }
            }

            if(nums2Idx == nums2.size()-1){
                if(nums1Idx == nums1.size()-1){
                    break;
                }else{
                    nums1Idx++;
                    nums2Idx= 0;
                    continue;
                }
            }

            int trySum1 = nums1[nums1Idx+1] + nums2[nums2Idx];
            int trySum2 = nums1[nums1Idx] + nums2[nums2Idx+1];

            if(trySum1 <= trySum2){
                nums1Idx++;
                continue;
            }else{
                nums2Idx++;
                continue;
            }
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> nums1 = {1,7,11};
        vector<int> nums2 = {2,4,6};
        int k = 3;
        vector<vector<int>>  expect = {{1,2},{1,4},{1,6}};
        vector<vector<int>> expect2 = {{1,2},{1,4},{1,6},{7,2},{7,4},{11,2},{7,6},{11,4},{11,6}};

        auto res = s.kSmallestPairs(nums1,nums2,k);
        assert(res == expect);
        auto res2 = s.kSmallestPairs(nums1,nums2,100);
        assert(res2 == expect2);
    }
    {
    }

}
