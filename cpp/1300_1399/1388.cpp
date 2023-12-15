#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {

        //just brute force
        //

        return recFind(slices);
    }

    int recFind(const vector<int>& slices){

        if(slices.empty()){
            return 0;
        }

        int subBest = 0;
        int maxTry = slices.size();

        for(int i = 0; i < maxTry ;++i){

            vector thisTry = slices;

            int thisV = slices[i];

            int alice = slices[(i - 1 + slices.size()) % slices.size()];
            int bob = slices[(i + 1 ) % slices.size()];



            thisTry.erase(thisTry.begin()+i);
            if(i == 0){
                thisTry.erase(thisTry.begin());
                thisTry.erase(thisTry.end() - 1);
            }else if(i == maxTry -  1){
                thisTry.erase(thisTry.end()-1);
                thisTry.erase(thisTry.begin());
            }else{
                thisTry.erase(thisTry.begin()+i);
                thisTry.erase(thisTry.begin()+i-1);
            }

            int subRes = recFind(thisTry);

            int thisTotal = thisV + subRes;

            subBest = max(subBest,thisTotal );
        }

        return subBest;
    }
};

int main(){
    Solution s;
    {
        vector<int> slices = {1,2,3,4,5,6};
        assert(s.maxSizeSlices(slices) == 10);
    }
}
