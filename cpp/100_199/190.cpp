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
    uint32_t reverseBits(uint32_t n) {

        constexpr uint32_t array[16][2] = {
            {1, (uint32_t(1))<<31},
            {1<<1, 1<<30},
            {1<<2, 1<<29},
            {1<<3, 1<<28},
            {1<<4, 1<<27},
            {1<<5, 1<<26},
            {1<<6, 1<<25},
            {1<<7, 1<<24},
            {1<<8, 1<<23},
            {1<<9, 1<<22},
            {1<<10, 1<<21},
            {1<<11, 1<<20},
            {1<<12, 1<<19},
            {1<<13, 1<<18},
            {1<<14, 1<<17},
            {1<<15, 1<<16},
            };
        for(int i = 0 ;i <16; ++i){

            uint32_t b0 = array[i][0] & n;
            uint32_t b1 = array[i][1] & n;

            if(b1){
                n |= array[i][0];
            }else{
                n &= ( 0xffffffff xor array[i][0]);
            }

            if(b0){
                n |= array[i][1];
            }else{
                n &= (0xffffffff xor array[i][1]);
            }

        }
        return n;
        
    }
};

int main(){
    Solution s;
    {

        uint32_t input = 0b10010110111001001101001111110101;
        uint32_t expect = 2949326697;

//  wrong (10101111110010101010011101101001)
//  right (10101111110010110010011101101001)


        assert(s.reverseBits(input)==expect);
    }
}
