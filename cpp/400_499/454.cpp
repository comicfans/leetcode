#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#ifdef LEETCODE
#include "../parse.h"
#endif

using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        sort(nums4.begin(),nums4.end());

        int sum34Min = nums3[0] + nums4[0];
        int sum34Max = nums3.back() + nums4.back();

        int sum234Min = nums2[0]  + nums3[0] + nums4[0];
        int sum234Max = nums2.back() + nums3.back() + nums4.back();

        int ret = 0;


        int nums1Min = 0 - sum234Max;
        int num1Max = 0 - sum234Min;

        for(auto it1 = lower_bound(nums1.begin(),nums1.end(), nums1Min),it1End = upper_bound(nums1.begin(), nums1.end(), num1Max); it1 < it1End; ){

            int v1 = *it1;

            int nums2Min = 0 - v1 - sum34Max;
            int nums2Max = 0 - v1 - sum34Min;

            auto it1Next = upper_bound(it1 + 1, it1End, v1);

            int mul1 = it1Next - it1;
            it1 = it1Next;

            for(auto it2 = lower_bound(nums2.begin(), nums2.end(), nums2Min),it2End = upper_bound(nums2.begin(),nums2.end(), nums2Max); it2 < it2End; ){


                int v2 = *it2;


                int nums3Min = 0 - v1 - v2 - nums4.back();
                int nums3Max = 0 - v1 - v2 - nums4.front();

                auto it2Next = upper_bound(it2+1 , it2End, v2);

                int mul2 = it2Next - it2;
                it2 = it2Next;

                for(auto it3 = lower_bound(nums3.begin(), nums3.end(), nums3Min),it3End = upper_bound(nums3.begin(),nums3.end(), nums3Max); it3 < it3End; ){

                    int v3 = *it3;
                    auto it3Next = upper_bound(it3+1, it3End, v3);
                    auto mul3 = it3Next - it3;
                    it3 = it3Next;

                    int expect4 = 0 - v1 - v2 - v3;
                    auto eq = equal_range(nums4.begin(),nums4.end(), expect4);
                    ret += (eq.second - eq.first) * mul1 * mul2 * mul3;


                }

            }

        }
        
        
        return ret;
    }
};

int main(){
    Solution s;
    {
        auto nums1 = pvi("454_case.txt", 0);
        auto nums2 = pvi("454_case.txt", 1);
        auto nums3 = pvi("454_case.txt", 2);
        auto nums4 = pvi("454_case.txt", 3);
        auto res = s.fourSumCount(nums1,nums2,nums3,nums4);
    }
    {
        auto nums1 = pvi("454_case.txt", 4);
        auto nums2 = pvi("454_case.txt", 5);
        auto nums3 = pvi("454_case.txt", 6);
        auto nums4 = pvi("454_case.txt", 7);
        auto res = s.fourSumCount(nums1,nums2,nums3,nums4);
    }
    {
        VI nums1 = {-1,-1},nums2 = {-1,1},nums3={-1,1},nums4 = {1,-1};
        auto res = s.fourSumCount(nums1,nums2,nums3,nums4);
        assert(res == 6);
    }
}
