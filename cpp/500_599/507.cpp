#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {

        int sum = 0;

        for(int i = 1; i <= num /2; ++i){
            if(num %i == 0){
                sum += i;
            }
        }

        return sum== num;
        
    }
};
