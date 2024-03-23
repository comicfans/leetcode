#include <vector>
#include <bit>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {

        int diff = x xor y;
        
        return popcount(static_cast<unsigned int>( diff));
    }
};
