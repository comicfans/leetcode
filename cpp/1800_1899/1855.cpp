#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int best = 0;
        for(int i = 0; i< nums1.size();++i){

            auto j = upper_bound(nums2.begin() + i,nums2.end(), nums1[i],[](auto & lhs, auto& rhs){
                return lhs > rhs;
            }) - nums2.begin();

            --j;
            
            if(j < 0 || j < i){
                continue;
            }


            best = max<int>(best, j-i);

        }

        return best;
        
    }
};

int main(
){
    Solution s;
    {
        vector<int> nums1 ={30,29,19,5};
        vector<int> nums2 = {25,25,25,25,25};
        assert(s.maxDistance(nums1,nums2) == 2);
    }
    {
        vector<int> nums1 = {55,30,5,4,2};
        vector<int> nums2 = {100,20,10,10,5};
        assert(s.maxDistance(nums1,nums2) ==2);
    }
}
