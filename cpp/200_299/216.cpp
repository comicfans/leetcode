#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>9){
            return {};
        }

        int minV = (1+k)*k/2;
        int maxV = (9+9-k+1) * k /2;
        if(n < minV || n > maxV){
            return {};
        }

        vector<vector<int>> ret;

        vector<int> chain;
        recFind(k,n,chain,ret);

        return ret;
        
    }
    void recFind(int k, int n, vector<int>& chain,vector<vector<int>>& ret){

        if(k == 1){
            int last = n;

            if(last>9){
                return;
            }

            if(chain.empty() || chain.back() < last){
                chain.push_back(last);
                ret.push_back(chain);
                chain.pop_back();
            }

            
            return;

        }

        if(k == 0){
            if(n == 0){
                ret.push_back(chain);
            }
            return;
        }

        for(int thisTry = chain.empty()?1:chain.back()+1; thisTry <= min(9,n); ++thisTry){
            chain.push_back(thisTry);

            recFind(k - 1,n - thisTry, chain,ret);
            chain.pop_back();
        }


        
    }
};



