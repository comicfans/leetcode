#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


#ifdef LEETCODE
#include "../parse.h"
#endif 

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        vector<int> sums(k);
        int best = numeric_limits<int>::min();

        for(int i = energy.size()-1;i >=  0; --i){
            const int mod = i%k;
            sums[mod] += energy[i];
            best = max(best, sums[mod]);
        }

        return best;
        
    }
};

#ifdef LEETCODE
int main(){
    Solution s;
    {
        VI input= {-2,-3,-1};
        auto res = s.maximumEnergy(input,2);
        assert(res == -1);
    }
    {
        //VI = {};
        //VVI = {};
    }
}
#endif 

