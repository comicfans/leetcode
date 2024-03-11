#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for(int i =1; i<=n; ++i){
            if(i % 15 == 0){
                ret[i-1] = "FizzBuzz";
                continue;
            }
            if(i % 3 == 0){
                ret[i-1] = "Fizz";
                continue;
            }
            if(i%5== 0){
                ret[i-1] ="Buzz";
                continue;
            }
            ret[i-1] = to_string(i);
        }
        return ret;
    }
};
