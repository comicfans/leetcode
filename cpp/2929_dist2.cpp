#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {

        long long ret = 0;

        if(limit*3 < n){
            return 0;
        }

        if(limit >= n){
            return (long long)(n+2) * (n+1) / 2;
        }

        for(int tryNumber = max(0, n - limit * 2); tryNumber <= min(limit,n); ++tryNumber){

            int left = n - tryNumber;

            
            int try2 = max(0, left - limit );
            int try2End = min(limit,left);

            ret+= (try2End - try2 + 1);
        }

        return ret;
    }


    
};

int main(){
    Solution s;
    assert(s.distributeCandies(5,2) == 3);
    assert(s.distributeCandies(3,3) == 10);
    s.distributeCandies(10001,20001);
}
