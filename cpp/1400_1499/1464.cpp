#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {


        int max1 = -1;
        int max2 = -1;

        for(auto v: nums){
            if(v > max1){
                swap(max1,max2);
                max1 = v;
                continue;
            }else{
                if(v > max2){
                    max2 = v;
                }
            }
        }

        return (max1-1) * (max2-1);
        
    }
};
