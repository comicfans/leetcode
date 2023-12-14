#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numWays(string s) {

        int oneNumber = 0;

        for(auto c: s){
            if(c=='1'){
                ++oneNumber;
            }
        }

        if(oneNumber % 3 != 0 ){
            return 0;
        }


        int onePart = oneNumber / 3;

        int mod = pow(10,9)+ 7;

        if(onePart == 0){
            long long res = (((long long)s.size() - 2 + 1) % mod ) * (((long long)s.size()-2) % mod)/ 2 % mod;
            return res;
        }


        
        int firstPos = -1;
        for(int i = 0;i < onePart; ++i){
            firstPos = s.find('1',firstPos+1);
        }

        //now firstPos point to nth one
        //

        int secondPos = firstPos ;

        int secondBegin = -1;
        for(int i = 0;i<onePart;++i){
            secondPos = s.find('1',secondPos + 1);
            if(secondBegin == -1){
                secondBegin = secondPos;
            }
        }

        int thirdBegin  = s.find('1', secondPos + 1);

        long long firstPick = secondBegin - firstPos;

        long long secondPick = thirdBegin - secondPos;

        int ret = (firstPick % mod) * (secondPick % mod) % mod;


        return ret;
    }
};

int main(){
}
