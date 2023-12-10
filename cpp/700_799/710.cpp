#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    Solution(int n, vector<int>& blacklist):black(blacklist),n_(n) {
        sort(black.begin(),black.end());
        last = -1;
    }
    
    int pick() {
        
        while(true){
            last = (last+1) % n_;
            if(binary_search(black.begin(),black.end(),last)){
                continue;
            }

            return last;
        }
    }
    vector<int>& black;
    int last ;
    int n_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
