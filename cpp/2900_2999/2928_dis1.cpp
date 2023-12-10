#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(int n, int limit) {
        return recF(n, limit, 3);
    }

    int recF(int n, int limit, int bucket ){

        int count = 0;

        if(bucket == 1){
            return n <= limit;
        }


        for(int tryNumber = max(0, n - limit * (bucket-1)); tryNumber <= min(limit,n); ++tryNumber){

            int sub = recF(n - tryNumber, limit, bucket- 1);

            count += sub;
        }

        return count;

    }
};

int main(){
    Solution s;
    assert(s.distributeCandies(5,2) == 3);
}
