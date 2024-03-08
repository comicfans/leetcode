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

        return recMin(1, n);
    }

    int recMin(int left, int right){
        assert(left <= right);

        if(left == right){
            return 0;
        }

        int thisBest = INT_MAX;
        for(int asRoot = left; asRoot <= right; ++asRoot){

            int leftWeight = (asRoot == left? 0: recMin(left, asRoot - 1));
            int rightWeight = (asRoot == right? 0: recMin(asRoot+1, right));

            int thisTotal = max(leftWeight , rightWeight) + asRoot;
            thisBest = min(thisBest, thisTotal);
        }

        return thisBest;
    }
};

int main(){
    Solution s;
    {
        assert(s.getMoneyAmount(10)== 16);
    }
}
