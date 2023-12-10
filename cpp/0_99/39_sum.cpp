#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ret;

        vector<int> existing;
        recFind(candidates, ret, existing, target, 0);
        return ret;
    }

    void recFind(const vector<int>& candidates, vector<vector<int>>& ret, vector<int>& existing, int left, int prevPick){

        if(left == 0){
            ret.push_back(existing);
            return;
        }


        for(int tryPos = prevPick ; tryPos < candidates.size(); ++tryPos){

            int thisValue = candidates[tryPos];
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
        vector<int> input = {2,3,6,7};
        s.combinationSum(input, 7);
    }

}
