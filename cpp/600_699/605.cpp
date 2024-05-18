#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int maxPossible = 0;

        int zeroCount = 1;
        for(int i = 0;i<flowerbed.size();++i){

            if(flowerbed[i]==0){
                ++zeroCount;
                continue;
            }

            int thisPossible = max(0,(zeroCount - 1)/2);
            maxPossible += thisPossible;
            if(maxPossible >= n){
                return true;
            }
            zeroCount = 0;
        }

        ++zeroCount;

        int thisPossible = max(0,(zeroCount - 1)/2);
        maxPossible += thisPossible;

        return n<= maxPossible;
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {1,0,0,0,1};
        bool res = s.canPlaceFlowers(input,1);
        assert(res);
    }
    {
        vector<int> input = {1,0,0,0,1};
        bool res = s.canPlaceFlowers(input,2);
        assert(!res);
    }
}
