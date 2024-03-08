#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lastRemaining(int n) {

        int left = 1;
        int right = n;

        int count = 0;
        int step = 1;
        while(left != right){
            int delta = right - left + step;
            assert(delta % step == 0);
            int number = delta / step;

            if(count == 0){

                right = right - (number %2 ) * step;
                left = left + step;

            }else{
                left = left + (number %2 ) * step;
                right = right - step;
            }

            step *=2;
            count = 1- count;

            assert(left <= right);
        }
        
        return left;
        
    }
};

int main(){
    Solution s;
    {
        assert(s.lastRemaining(9)==6);
    }
}
