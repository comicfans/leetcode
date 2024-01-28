#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minCut(string s) {

        vector<int> cache(s.size(),numeric_limits<int>::max());
        return recFill(s, 0, cache)-1;

        
    }

    int recFill(const string& s, int begin, vector<int>& cache){

        if(begin == s.size()){
            return 0;
        }

        if(cache[begin]!= numeric_limits<int>::max()){
            return cache[begin];
        }

        int subBest = numeric_limits<int>::max();
        for(int end = begin +1; end <= s.size(); ++end){

            bool ok = true;
            for(int check = begin; check < (begin+end)/2;++check){
                if(s[check] != s[end - 1-(check - begin)]){
                    ok=false;
                    break;
                }
            }
            if(!ok){
                continue;
            }
            int thisSub = recFill(s, end, cache);
            subBest = min(subBest, thisSub);
        }

        if(subBest == numeric_limits<int>::max()){
            return subBest;
        }

        cache[begin] = subBest + 1;
        return cache[begin];
    }
};

int main(){
    Solution s;
    {
        assert(s.minCut("aab")==1);
        assert(s.minCut("a")==0);
    }
}
