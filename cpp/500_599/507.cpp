#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {

       vector<pair<int,int>> primes;

       int maxPossible = num/2;
        int div = num;
       for(int i = 2; i<=maxPossible; ++i){

            if(div % i != 0){
                continue;
            }

            bool is = true;
            for(auto [p,count] : primes){
                if(i % p == 0){
                    is = false;
                    break;
                }
            }

            if(!is){
                continue;
            }

            primes.push_back({i,1});
            div /= i;
            while(div % i == 0){
                primes.back().second ++;
                div /= i;
            }

            if(div == 1){
                break;
            }
       }

        if(div != 1){
            primes.push_back({div, 1});
        }



        // 2 x2 
        // 7 x1
        int sum = rec(primes,0,1);

        return sum == num + num;
    }

    int rec(const vector<pair<int,int>>& primes, int pos, int prod){
        if(pos == primes.size()){
            return prod;
        }

        int v = primes[pos].first;
        int count = primes[pos].second;

        int thisProd = 1;
        int totalSum = 0;
        for(int tryCount = 0; tryCount <= count; ++tryCount){

            int thisSub = rec(primes, pos+1, thisProd * prod);

            totalSum += thisSub;
            if(tryCount == count){
                break;
            }
            thisProd *= v;
        }

        return totalSum;
    }
};

int main(){
    Solution s;
    assert(s.checkPerfectNumber(86243));
    assert(s.checkPerfectNumber(28));
    assert(!s.checkPerfectNumber(7));
}
