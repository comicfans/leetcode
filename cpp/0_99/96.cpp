#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numTrees(int n) {
        
        vector<int> cache(n+1);

        cache[1] = 1;
        cache[0] = 1;

        for(int i = 2; i<=n;++i){

            for(int pick = 0;pick <i; ++pick){
                int left = pick;
                int right = i-1-pick;

                cache[i]+= cache[left] * cache[right];
            }
        }

        return cache[n];

    }
};

int main(){
    Solution s;
    {
        assert(s.numTrees(3)== 5);
        assert(s.numTrees(1)== 1);
    }
}
