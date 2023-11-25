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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ret;

        vector<int> existing;
        recFind(candidates, ret, existing, target, -1);
        return ret;
    }

    void recFind(const vector<int>& candidates, vector<vector<int>>& ret, vector<int>& existing, int left, int prevPick){

        if(left == 0){
            ret.push_back(existing);
            return;
        }


        int prevTryValue = 0;
        for(int tryPos = prevPick+1 ; tryPos < candidates.size(); ++tryPos){

            int thisValue = candidates[tryPos];

            if(thisValue == prevTryValue){
                continue;
            }
            prevTryValue = thisValue;

            if(thisValue > left){
                break;
            }

            existing.push_back(thisValue);

            recFind(candidates, ret, existing, left - thisValue, tryPos);

            existing.pop_back();
        }
    }
};


int main(){
    Solution s;
    {
        vector<int> input = {10,1,2,7,6,1,5};
        s.combinationSum2(input,8);
    }
}
