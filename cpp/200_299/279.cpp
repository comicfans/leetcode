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
    int numSquares(int n) {

        map<int,int> cache;
        return recFind(n, cache);
    }

    int recFind(int left, map<int,int>& cache){
        if(left == 0){
            return 0;
        }

        auto cachePos = cache.find(left);
        if(cachePos != cache.end()){
            return cachePos -> second;
        }

        //how many to sub ?
        int root = int(sqrt(left));


        int bestSub = numeric_limits<int>::max();
        for(int tryRoot = root; tryRoot >= 1; --tryRoot){

            int thisLeft = left - tryRoot * tryRoot;
            int thisRes = recFind( thisLeft,  cache);
            

            bestSub = min(thisRes, bestSub);
        }

        if(bestSub != numeric_limits<int>::max()){
            cache[left] = bestSub + 1;
        }

        return bestSub + 1;

    }
};

int main(){
    Solution s;
    {
        assert(s.numSquares(22) == 3);
        assert(s.numSquares(19) == 3);
        assert(s.numSquares(44) == 3);
    }
}
