#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {

        map<pair<int,int>,int> cache;
        int res = recMin(1, n, cache);
        return res;
    }

    int recMin(int left, int right, map<pair<int,int>,int>& cache){
        assert(left <= right);

        if(left == right){
            return 0;
        }

        auto pos = cache.find({left,right});
        if(pos != cache.end()){
            return pos->second;
        }


        int thisBest = INT_MAX;
        for(int asRoot = right; asRoot >= left; --asRoot){

            int leftWeight = (asRoot == left? 0: recMin(left, asRoot - 1, cache));
            int rightWeight = (asRoot == right? 0: recMin(asRoot+1, right, cache));

            int maxSub = max(leftWeight , rightWeight);

            int thisTotal = maxSub + asRoot;
            thisBest = min(thisBest, thisTotal);

        }

        cache[{left,right}] = thisBest;

        return thisBest;
    }
};

int main(){
    Solution s;
    {
        assert(s.getMoneyAmount(10)== 16);
        s.getMoneyAmount(25);
    }
}

