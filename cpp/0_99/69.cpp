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
    int mySqrt(int x) {

        return recFind(x, 0 , pow(2,16));
    }

    int recFind(long long pow2, int low, int high){

        assert(pow2 >= (long long)low* low && pow2 <= (long long)high* high);
        if(high - low <=1 ){
            return low;
        }



        int half = (low + high)/2;

        long long half2 = (long long)half * half;
        if(pow2 >= half2){
            return recFind(pow2, half,high);
        }

        return recFind(pow2,low,half);

    }

};

int main(){
    Solution s;
    {
        assert(s.mySqrt(4) == 2);
    }
{
        assert(s.mySqrt(8) == 2);
    }
{
        assert(s.mySqrt(9) == 3);
    }
}
