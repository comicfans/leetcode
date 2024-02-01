#include <vector>
#include <cstdint>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {


        int move = right - left ;

        int ret = 0;
        int bitwise = 0;
        for(int bit = 0; bit < 32; ++bit){

            uint32_t orBit = ((uint32_t)1<<bit);
            if(orBit > left && orBit > right){
                break;
            }

            int lb = orBit & left;

            if(lb == 0){
                bitwise += orBit;
                continue;
            }

            int rb = orBit & right;
            if(rb == 0){
                bitwise += orBit;
                continue;
            }

            int lower = left & bitwise;
            bitwise += orBit;

            int stepTo0 = orBit  - lower;
            if(stepTo0 <= move){
                continue;
            }
            ret += orBit;


        }

        return ret;
        
    }
};

int main(){

    Solution s;
    {
        int left = 5, right = 7;
        assert(s.rangeBitwiseAnd(left,right) == 4);
    }
    {
        int left = 1, right = 2147483647;
        assert(s.rangeBitwiseAnd(left,right) == 0);
    }
}
