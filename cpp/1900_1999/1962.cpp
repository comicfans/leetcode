#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        if(piles.empty()){
            return 0;
        }

        multiset<int> s;
        for(auto v:piles){
            s.insert(v);
        }

        for(int i = 0; i < k;++i){
            auto pos = s.end();
            --pos;

            int changed = *pos;
            s.erase(pos);

            int remove = changed / 2;
            changed-=remove;

            s.insert(changed);
        }

        auto res = accumulate(s.begin(),s.end(),0);

        return res;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> piles = {5,4,9};
        int k = 2;
        assert(s.minStoneSum(piles,k) == 12);
    }
}
