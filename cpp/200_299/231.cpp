#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        vector<int> possible = {1};
        for(int i = 1; i< 31;++i){
            possible.push_back(possible.back()*2);
        }
        return binary_search(possible.begin(),possible.end(),n);
    }
};
