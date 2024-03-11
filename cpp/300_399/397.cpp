#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int integerReplacement(int n) {
        return rec((long)n);
    }

    int rec(long n){

        if(n == 1){
            return 0;
        }

        if(n % 2 == 0){
            return rec(n/2)+1;
        }

        return min(rec(n+1), rec(n-1))+1;
    }
};
