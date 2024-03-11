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

        vector<vector<int>> cache(n, vector<int>(n,INT_MAX));
        int res = recMin(1, n, cache);
        return res;
    }

    int recMin(int left, int right, vector<vector<int>>& cache){
        assert(left <= right);

        if(left == right){
            return 0;
        }

        int hit= cache[left-1][right - 1] ;
        if(hit!= INT_MAX){
            return hit;
        }
        
        int thisBest = INT_MAX;
        for(int asRoot = right; asRoot >= left; --asRoot){

            int leftWeight = (asRoot == left? 0: recMin(left, asRoot - 1, cache));
            int rightWeight = (asRoot == right? 0: recMin(asRoot+1, right, cache));

            int maxSub = max(leftWeight , rightWeight);

            int thisTotal = maxSub + asRoot;
            thisBest = min(thisBest, thisTotal);

        }

        cache[left-1][right-1] = thisBest;

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

