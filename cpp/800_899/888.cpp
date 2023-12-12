#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

        auto aSum = accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        sort(aliceSizes.begin(),aliceSizes.end());

        auto bSum = accumulate(bobSizes.begin(),bobSizes.end(),0);
        sort(bobSizes.begin(),bobSizes.end());

        int delta = aSum - (aSum+bSum)/2;

        vector<int> ret(2);
        for(auto v: aliceSizes){
            int target = v - delta;
            if(target <= 0){
                continue;
            }

            if(binary_search(bobSizes.begin(),bobSizes.end(),target)){
                ret[0] = v;
                ret[1] = target;
                break;
            }
        }

        return ret;


        
    }
};
