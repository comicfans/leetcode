#include <cassert>

class Solution {
public:
    int differenceOfSums(int n, int m){
        auto divGroup = n / m;
        auto totalSum = (1+n) * n / 2;

        auto divSum = (1+divGroup) * divGroup / 2 * m;

        auto another = totalSum - divSum;

        return another - divSum;
    }
};

int main(){

    int cases[][3] = {{10,3,19},{5,6,15},{5,1,-15}};

    Solution s;
    for(auto &p : cases){

        auto res = s.differenceOfSums(p[0],p[1]);

        assert(res == p[2]);

    }
}
