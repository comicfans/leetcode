#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {

        auto p = haystack.find(needle);

        return p== string::npos?-1:p;
        
    }
};
