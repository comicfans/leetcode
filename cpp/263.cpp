#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isUgly(int v) {

        if(v<0){
            return false;
        }


        long long n = v;
        int div[] = {2,3,5};

        while(n > 1){

            bool atLeastOne = false;
            for(auto d: div){

                if(n %d == 0){
                    atLeastOne = true;
                    n/=d;
                    continue;
                }


            }
            if(!atLeastOne){
                return false;
            }

        }

        return true;
    }
};
