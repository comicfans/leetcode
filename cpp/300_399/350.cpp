#include <iterator>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        //nums1.resize(unique(nums1.begin(),nums1.end()) - nums1.begin());

        sort(nums2.begin(),nums2.end());
        //nums2.resize(unique(nums2.begin(),nums2.end()) - nums2.begin());

        vector<int> ret;
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(), back_inserter(ret));
        return ret;
    }
};
   
