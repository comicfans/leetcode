#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int totalMoney(int n) {

        int weeks = n / 7;

        int firstWeek = (1+ 7) * 7 / 2;

        int lastWeek = firstWeek + 7 * (weeks-1);

        int totalWeeks = (firstWeek + lastWeek) * weeks / 2;

        int leftDays = n % 7;

        int leftFirst = 1 + ((n+6)/7 -1);

        int leftLast = (n - weeks * 7 ) + leftFirst-1;

        int left = (leftFirst + leftLast) * leftDays / 2;

        return totalWeeks + left;

        
    }
};
