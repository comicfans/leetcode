#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        std::merge(nums1.begin(),nums1.begin()+m,
              nums2.begin(),nums2.begin()+n,
              back_inserter(result));
        swap(nums1,result);
    }
};
