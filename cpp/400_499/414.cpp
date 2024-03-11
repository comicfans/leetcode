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
    int thirdMax(vector<int>& nums) {
        vector<int> max3;

        for(auto v: nums){

            auto pos = lower_bound(max3.begin(),max3.end(),v, [](auto lhs, auto rhs){return lhs > rhs;});

            if(max3.size()==3 && pos == max3.end()){
                continue;
            }

            max3.insert(pos, v);
            max3.resize(unique(max3.begin(),max3.end()) - max3.begin());
            max3.resize(min((int)max3.size(),3));
        }

        if(max3.size() < 3){
            return max3.front();
        }

        return max3.back();
        
    }
};

int main(){
    Solution s;
    {

        VI nums = {5,2,4,1,3,6,0};
        assert(s.thirdMax(nums)==4);
    }
}
