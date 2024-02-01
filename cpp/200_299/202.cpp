#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        
        if(n==1){
            return true;
        }
        if(n==0){
            return false;
        }

        set<int> hit={n};

        while(true){
            int sum = 0;
            while(n > 0){
                int digit = n % 10;
                sum += digit * digit;
                n/=10;
            }

            if(sum == 0){
                return false;
            }
            if(sum == 1){
                return true;
            }
            if(hit.count(sum)){
                return false;
            }
            hit.insert(sum);
            n = sum;
        }
    }
};
