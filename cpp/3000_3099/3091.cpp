#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minOperations(int k) {

        int best = INT_MAX;
        for(int inc = 0; (1+inc) <= k;++inc){

            int base = 1 + inc;
            int mul = (k+inc)/ base - 1;

            int current = inc + mul;

            best = min(best, current);


        }


        return best;
    }
};

int main(){
    Solution s;
    {
        auto res = s.minOperations(11);
        assert(res == 5);
    }
    {
        auto res = s.minOperations(1);
        assert(res == 0);
    }
}
