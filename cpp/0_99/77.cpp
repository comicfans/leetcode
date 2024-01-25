#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ret;

        vector<int> prev;
        prev.reserve(k);
        vector<int> avaiable(n);
        for(int i = 0; i<k; ++i){
            prev.push_back(i+1);
            avaiable[i]= 0;
        }

        ret.push_back(prev);

        while(true){
            // 1,2,3 => 1,2,4
            //
            // 3,2,1 =>3,2,  x2, x3, 
            //
            // 4,1,2
            // 4,1,3
            // 4,2,1
            // 4,2,3
            // 4,3,1
            // 4,3,2
            //
            // 3,1,2 = > 3,2,1

            for(int b = 0; b < k; ++b){
                int currentNumber = prev[prev.size()-1 - b]-1;
                //find next avaiable
                bool hasFound = false;
                for(int tryNext = currentNumber+1;tryNext < n; ++ tryNext){
                    if(avaiable[tryNext]){
                        hasFound = true;
                    }
                }

            }

        }

        return ret;
    }
};
