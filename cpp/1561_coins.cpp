#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {

        sort(piles.begin(),piles.end(), [](auto lhs,auto rhs){return lhs > rhs;});

        int ret = 0;
        int group = piles.size()/3;
        for(int i=0;i<group;++i){
            ret+= piles[i * 2+1];
        }

        return ret;
        
    }
};
