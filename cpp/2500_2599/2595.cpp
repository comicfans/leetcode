#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> evenOddBit(int n) {

        int pos = 0;

        vector<int> ret(2);

        while(n> 0){

            int thisBit = n % 2;
            ret[pos % 2] += thisBit;
            n /= 2;
            ++pos;
        }

        return ret;
        
    }
};
