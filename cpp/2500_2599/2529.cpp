#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumCount(vector<int>& nums) {
     int pos=0;
     int neg=0;
     for(auto v:nums){
         if(v > 0){
             ++pos;
         }
         if(v < 0){
             ++neg;
         }
     }   
     return max(pos,neg);
    }
};
