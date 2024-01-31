#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {

        int totalCount5 = 0;

        while(n>0){

            //41 / 5 = 8
            int count5 = n /5;
            // 5, 10, 15, 20, 25, 30, 35, 40  ...

            totalCount5+= count5;

            n = count5;
        }


        // 25, 50, 75, 100


        return totalCount5;
        
    }
};
