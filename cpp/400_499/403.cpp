#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones) {

        vector<pair<bool,set<int>>> canReachPrev(stones.size(),{false,{}});

        canReachPrev[0].first = true;
        canReachPrev[0].second = {0};

        
        return rec(stones, canReachPrev, 0, 0);
    }

    bool rec(const vector<int>& stones, vector<pair<bool,set<int>>>& canReachPrev, int root, int prevStep){

        if(root == canReachPrev.size()-1){
            return true;
        }

        for(int offset:{-1,0,1}){


        int thisStep1 = prevStep + offset;
            if(thisStep1<=0){
                continue;
            }

            int nextPos = stones[root] + thisStep1;
            auto try1 = lower_bound(stones.begin() + root+1, stones.end(), stones[root]+ thisStep1) - stones.begin();
            if(try1 == stones.size()){
                    continue;
            }

            if(stones[try1] != nextPos){
                continue;
            }

            canReachPrev[try1].first = true;
            if(canReachPrev[try1].second.count(thisStep1)){
                continue;
            }
            
            canReachPrev[try1].second.insert(thisStep1);

            bool subOk = rec(stones, canReachPrev, try1, thisStep1);
            if(subOk){
                    return true;
            }

        }

        return false;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> stones = {0,1,3,5,6,8,12,17};
        assert(s.canCross(stones));
    }
}
