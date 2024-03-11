#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findNthDigit(int s) {

        int64_t n = s;
        // 1-9  9
        // 10-99 90 * 2
        // 100-999 900 * 3
        // 1000-9999 9000 * 4
        //
        int64_t step = 9;
        int64_t width = 1;

        int base = 1;
        while(n > step * width){
            n -= step * width;

            base = base + step;
            step *=10;
            width += 1;
        }

        int index = (n-1) / width;
        int number = base + index ;

        vector<int> digits;
        while(number > 0){
            digits.push_back(number % 10);
            number/=10;
        }
        //1 ~ 9, 1 0
        //       1,2

        int left = (n-1) % width;
        int rIdx = digits.size()-1-left;
        return digits[rIdx];
    }
};

int main(){
    Solution s;
    {
        auto res = s.findNthDigit(1000000000);
    }
    {
        auto res = s.findNthDigit(1000);
        // 1~9          9
        // 10~99      180
        // 100 ~ 369  810 
        //            999
        // 370        3
        assert(res == 3);
    }
    {
        auto res = s.findNthDigit(10);
        assert(res == 1);

    }
    {
        auto res = s.findNthDigit(3);
        assert(res == 3);

    }
    {
        auto res = s.findNthDigit(11);
        assert(res == 0);

    }
}
