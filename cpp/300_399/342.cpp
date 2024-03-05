#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


        constexpr int possible[] = {1,4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
    
class Solution {
public:
    bool isPowerOfFour(int n) {
    return binary_search(begin(possible),end(possible),n);
    }
};
