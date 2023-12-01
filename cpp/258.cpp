#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int addDigits(int num) {


        int sum = 0;

        while(num >= 10){
            int sum = 0;
            while(num > 0){
                sum+=num % 10;
                num /= 10;
            }
            num = sum;
        }


        return num;
    }

    
};
