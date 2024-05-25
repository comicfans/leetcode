#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        int isEven = -1;
        for(auto v: nums){
            int thisIsEven = (v % 2 == 0);
            if((int)thisIsEven == isEven){
                return false;
            }
            isEven = thisIsEven;
        }

        return true;
        
    }
};
