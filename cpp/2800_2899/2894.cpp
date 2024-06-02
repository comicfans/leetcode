#include <cassert>

class Solution {
public:
    int differenceOfSums(int n, int m) {

        int maxDiv = n / m; 
        int totalSum = (1+n)* n /2;

        int sumOfDiv= (1+maxDiv) * maxDiv / 2 * m;

        int another = totalSum - sumOfDiv;

        return sumOfDiv - another;
        
    }
};

int main(){

    int input[][3] = {{10,3,19},{ 5,6,15}, {5,1,-15}};

    Solution s;

    for(auto& tup: input){

        int res = s.differenceOfSums(tup[0], tup[1]);
        assert(res == tup[2]);

    }

}
