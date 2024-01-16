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
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        vector<pair<int,int>> deltaIdx(nums1.size());
        for(int i = 0;i<nums1.size();++i){
            deltaIdx[i] = {abs(nums1[i] - nums2[i]),i};
        }


        sort(deltaIdx.begin(),deltaIdx.end());


        sort(nums1.begin(),nums1.end());

        vector<int> deltaDelta;
        deltaDelta.reserve(nums1.size());

        for(int i = 0;i < nums1.size(); ++ i){

            auto p = deltaIdx[nums1.size()-1-i];
            if(p.first == 0){
                break;
            }

            int n2 = nums2[p.second];

            auto lower = lower_bound(nums1.begin(),nums1.end(), n2) - nums1.begin();

            int tryLeft = numeric_limits<int>::max();
            if(lower > 0){
                tryLeft = abs(nums1[lower-1] - n2);
            }

            int tryRight = numeric_limits<int>::max();
            if(lower != nums1.size()){
                tryRight = abs(nums1[lower] - n2);
            }

            int newDelta = min(tryLeft,tryRight);
            if(newDelta >= p.first){
                continue;
            }

            deltaDelta.push_back(p.first - newDelta);
        }

        int reduceDelta = 0;
        if(!deltaDelta.empty()){
            reduceDelta = *max_element(deltaDelta.begin(),deltaDelta.end());
        }


        long long allSum = 0;

        for(int i =0; i < deltaIdx.size(); ++i){

            allSum += deltaIdx[i].first;

            allSum = allSum % (1000000007);
        }

        allSum -= reduceDelta;
        allSum += 1000000007;
        allSum %= 1000000007;
        
        return allSum;
    }
};

int main(){
    Solution s;
    {
        vector<int> nums1 = {1,7,5}, nums2 = {2,3,5};
        assert(s.minAbsoluteSumDiff(nums1,nums2) == 3);
    }
    {
    vector<int> nums1 = {2,4,6,8,10}, nums2 = {2,4,6,8,10};
        assert(s.minAbsoluteSumDiff(nums1,nums2)==0);
    }
    {
         vector<int> nums1 = {1,10,4,4,2,7}, nums2 = {9,3,5,1,7,4};
        assert(s.minAbsoluteSumDiff(nums1,nums2)==20);
    }
}

