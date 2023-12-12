#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        while(n>0){
            int digit = n % 10;
            prod *= digit;
            sum+= digit;
            n /= 10;
        }
        return prod - sum;
    }
};
