#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#ifdef LEETCODE
int pick = 0;
int guess(int num){
    if(num  > pick){
        return -1;
    }

    if(num < pick){
        return 1;
    }

    return 0;
}
#endif

using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        long left =  0;
        long right = (long)n+1;

        while(left != right){

            int next = (left + right)/2;
            if(next == left){
                return right;
            }

            int res = guess(next);

            if(res == 0){
                return next;
            }

            if(res < 0){
                right = next;
                continue;
            }

            left = next;
        }

        return left;
        
    }
};
