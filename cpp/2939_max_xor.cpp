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
    int maximumXorProduct(long long a, long long b, int n) {
        // to make value xor n max, must makes it more 1 at binary bit
        
        auto toBin = [](long long v){
            vector<bool> ret;

            while(v>0){
                ret.push_back(v%2);
                v/=2;
            }
            return ret;
        };

        auto binA = toBin(a);
        auto binB = toBin(b);
        int abHighestBit = max(binA.size(),binB.size());


        int maxBit = max(abHighestBit, n);

        int fill1Size = max(0, maxBit - abHighestBit);

        binA.resize(maxBit);
        fill_n(binA.begin()+abHighestBit, fill1Size, 1);

        binB.resize(maxBit);
        fill_n(binB.begin()+abHighestBit, fill1Size, 1);


        int biggerOne = -1;

        int compareStart = min(abHighestBit, n)-1;

        for(int highBit = abHighestBit - 1; highBit >=0 ;--highBit){
            if(binA[highBit] == binB[highBit]){
                if(highBit <= compareStart){
                    binA[highBit] = 1;
                    binB[highBit] = 1;
                }
                continue;
            }

            //diff 
            if(biggerOne == -1){

                biggerOne = b > a;
                //this is first diff
                continue;
            }

            if(highBit > compareStart){
                continue;
            }

            binA[highBit] = biggerOne;
            binB[highBit] = 1-biggerOne;
        }


        //now a/b prepared, convert back a/b to long long

        auto toDec = [](const vector<bool>& bin){
            long long ret = 0;
            for(int idx = 0;idx < bin.size(); ++idx){
                ret += (long long)bin[idx] << idx;
            }
            return ret;
        };

        auto decA = toDec(binA);
        auto decB = toDec(binB);

        auto mod = (long long)pow(10,9)+7;

        auto modA = decA % mod;
        auto modB = decB % mod;
        auto res = (modA * modB) % mod;

        return res;
    }
};
int main(){
    Solution s;
    assert(s.maximumXorProduct(12,5,4) == 98);
    assert(s.maximumXorProduct(6,7,5) == 930);
    assert(s.maximumXorProduct(1,6,3) == 12);
    assert(s.maximumXorProduct(0,7,2) == 12);
    assert(s.maximumXorProduct(0,4,0) == 0);
}
