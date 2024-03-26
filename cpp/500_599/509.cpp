#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int fib(int n) {
        int i0 = 0;
        int i1 = 1;
        if(n<2){
            return n;
        }

        for(int k = 2;k<=n; ++k){
            int ik = i0 + i1;
            i0 = i1;
            i1 = ik;
        }

        return i1;
        
    }
};
