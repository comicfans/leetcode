#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(),envelopes.end());

        vector<int> best(envelopes.size());


        return  rec(envelopes, 0, best, -1, 0);
        
    }

    int rec(const vector<vector<int>>& envelopes, int pos,vector<int>& best, int parent, int currentLength){

        if(pos == envelopes.size()){

            return 0;
        }

        

        bool canUseThis = false;
        if(parent == -1){
            canUseThis = true;
        }else{
            auto parentEnv = envelopes[parent];
            canUseThis = (parentEnv[0]< envelopes[pos][0] && parentEnv[1] < envelopes[pos][1]);
        } 


        if(!canUseThis){
            auto notUseThis = rec(envelopes, pos+1, best ,parent, currentLength);
            return notUseThis;
        }

        int useThisRes = best[pos];
        if(useThisRes==0){
            auto subRes = rec(envelopes, pos+1, best, pos, currentLength+1);
            best[pos] = subRes+ 1;
            useThisRes = best[pos];
        }

        

        auto notUseThisRes = rec(envelopes,pos+1, best,parent,  currentLength);

            return max(best[pos],notUseThisRes);

    }
};

int main(){

    Solution s;
    {
vector<vector<int>> env = {{15,22},{8,34},{44,40},{9,17},{43,23},{4,7},{20,8},{30,46},{39,36},{45,14},{24,19},{24,36},{31,34},{32,19},{29,13},{16,48},{8,36},{44,2},{11,5},{2,50},{29,6},{18,38},{15,49},{22,37},{6,20},{25,11},{1,50},{19,40},{45,35},{37,21},{4,29},{40,5},{4,49},{1,45},{14,32},{14,37},{23,22},{31,21},{2,36},{43,4},{21,32},{41,2},{44,32},{36,20},{22,45},{3,41},{44,29},{29,33},{42,2},{38,17},{43,26},{30,15},{28,12},{33,30},{49,7},{8,14},{1,9},{41,25},{7,15},{26,32},{11,33},{12,45},{33,7},{16,34},{39,1},{20,49},{50,45},{14,29},{50,41},{1,45},{14,43},{49,20},{41,37},{43,22},{45,19},{20,21},{28,19},{2,1},{7,49},{3,3},{49,48},{34,35},{10,2}};
        int res = s.maxEnvelopes(env) ;
        assert(res == 16);
    }
    {
        vector<vector<int>> env = {{7,10},{14,7},{3,16},{6,3},{7,9},{5,2},{10,1},{6,11},{18,20}};
        int res = s.maxEnvelopes(env) ;
    }
    {
        vector<vector<int>> env = {{5,4},{6,4},{6,7},{2,3}};
        int res = s.maxEnvelopes(env) ;
        assert(res == 3);
    }
    {

        vector<vector<int>> env = {{1,1},{1,1},{1,1}};
        assert(s.maxEnvelopes(env) == 1);
    }
}
