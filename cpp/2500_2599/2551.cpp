#include <limits>
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
    long long putMarbles(vector<int>& weights, int k) {
        if(k == weights.size()){
            return 0;
        }

        vector<int> adjSum(weights.size()-1) ;

        for(int i = 1;i < weights.size();++i){
            adjSum[i-1] = weights[i-1]+weights[i];
        }

        sort(adjSum.begin(),adjSum.end());

        long long minRes = accumulate(adjSum.begin(),adjSum.begin() + k-1, (long long)0);
        long long maxRes = accumulate(adjSum.begin() + adjSum.size() - (k-1), adjSum.end(), (long long)0);

        return maxRes - minRes;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> weights = {1,3,5,1};
        assert(s.putMarbles(weights,2) == 4);
    }
    {
        vector<int> weights = {1,3};
        assert(s.putMarbles(weights,2) == 0);
    }
    {
        vector<int> weights = {1,4,2,5,2};
        assert(s.putMarbles(weights,3) == 3);
    }
}
