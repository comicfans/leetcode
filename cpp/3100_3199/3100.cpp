#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int res = numBottles;
        int empty = res;

        int require = numExchange;
        while(empty >= require){
            empty -= require;
            ++res;
            ++empty;
            ++require;
        }


        return res;
        
    }
};

int main(){
    Solution s;
    {
        auto res = s.maxBottlesDrunk(10,3);
        assert(res == 13);
    }
    {
        auto res = s.maxBottlesDrunk(13,6);
        assert(res == 15);
    }
}
