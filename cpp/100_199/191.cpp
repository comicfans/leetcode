#include <cstdint>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {

        int count = 0;
        while(n>0){
            count += n%2;
            n/= 2;
        }
        
        return count;
    }
};
