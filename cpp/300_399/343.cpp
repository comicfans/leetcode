#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int integerBreak(int n) {

        if(n==2){
            return 1;
        }

        if(n==3){
            return 2;
        }


        // 9 -> 2*2*2*3 -> 24
        //      4*5    ->20
        //      4*3*2  ->24
        //      3*3*3  -> 27
        //      why not choose 5, because 2*3 > 5
        // so choose only 3,4

        int count3 = n /3 ;
        int left = n % 3;
        if(left == 0){
            return pow(3, count3);
        }

        if(left == 1){
            return pow(3, max(count3 - 1,0)) * 4;
        }

        //left == 2
        return pow(3, count3) * 2;
        
    }
};
