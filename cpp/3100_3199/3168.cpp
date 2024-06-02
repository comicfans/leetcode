#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>


using namespace std;

#ifdef LEETCODE
#include "../parse.h"
#endif

// jj
class Solution {
public:
    int minimumChairs(string s) {
        int count = 0;
        int res = 0;
        for(auto ch:s){
            if(ch == 'E'){
                ++count;
                res = max(count,res);
            }
            if(ch == 'L'){
                --count;
            }
        }

        return res;
        
    }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
