#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfMatches(int n) {

        int next = n;

        int ret = 0;

        while(next!=1){
            ret += next/2;
            next = next/2+next%2;
        }

        return ret;


        
    }
};
