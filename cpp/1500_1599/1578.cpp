#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int ret = 0;

        int colorHead = 0;
        while(colorHead!=colors.size()){
            char thisColor = colors[colorHead];
            int idxEnd = find_if(colors.begin()+colorHead,colors.end(),[=](auto c){
                return c != thisColor;
            }) - colors.begin();

            if(idxEnd - colorHead==1){
                colorHead = idxEnd;
                continue;
            }
            

            int maxElement = 0;
            int thisSpend = 0;
            for(int i = colorHead;i<idxEnd;++i){
                thisSpend += neededTime[i];
                maxElement = max(maxElement,neededTime[i]);
            }

            thisSpend -= maxElement;

            ret+=thisSpend;
            colorHead=  idxEnd;
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        string colors = "abaac";
        vector<int> neededTime = {1,2,3,4,5};
        int expect = 3;
        assert(s.minCost(colors,neededTime) ==expect);
    }
}
