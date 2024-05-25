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




//jj
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {

        map<string,int> counts;

        for(int i =0; i< word.size();){

            string sub = word.substr(i , k);
            counts[sub]++;
            i+= k;
        }
        
        int maxCount = 0;
        for(auto &kv: counts){
            maxCount = max(maxCount,kv.second);
        }

        return word.size() / k - maxCount;
    }
};







#ifdef LEETCODE
int main(){
    Solution s;
    {
        //VI = {};
        //VVI = {};
    }
    {
        //VI = {};
        //VVI = {};
    }
}
#endif 

