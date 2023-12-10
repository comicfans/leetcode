#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {


        int reachN = 0;
        int reachValue = 1;

        for(int testValue =1; reachN<n;
            ++testValue){

            if(testValue == 1){
                ++reachN;
                reachValue=testValue; 
                continue;
            }

            int div = testValue;

            while(div>1){
                bool atLeastOnce = false;
                for(const auto p: primes){
                    if(p > div){
                        break;
                    }
                    if(div %p == 0){
                        div /= p;
                        atLeastOnce = true;
                    }
                }
                if(!atLeastOnce){
                    break;
                }
            }

            if(div == 1){
                reachValue = testValue;
                ++reachN;
            }
            
        }

        return reachValue;
    }
};

int main(){
    Solution s;
    {
        vector<int> seq{2,7,13,19};
        assert(s.nthSuperUglyNumber(12,seq) == 32);
    }
    too slow
}
