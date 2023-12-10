#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {

        
        int n1 = 1;
        int n2 = 2;

        if(n <= 3){
            return n;
        }


        for(int i = 2; i < n;++i){
            int next = n1 + n2;
            n1 = n2;
            n2 = next;
        }

        return n2;


    }


};
