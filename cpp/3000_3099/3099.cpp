#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        
        int sum = 0;
        int copy = x;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }

        return (copy % sum == 0)?sum:-1 ;
    }
};

int main(){
    Solution s;
    {
        int res = s.sumOfTheDigitsOfHarshadNumber(23);
        assert(res == -1);
    }
}
