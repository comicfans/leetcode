#include <cassert>

using namespace std;
class Solution {
public:
    int sumBase(int n, int k) {

        int result = 0;

        while(n>0){
            result += (n % k);
            n /= k;
        }

        return result;
        
    }
};

int main(){

    Solution s;
    assert(s.sumBase(34,6)==9);
    assert(s.sumBase(10,10)==1);

}
