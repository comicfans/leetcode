#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {


        vector<int> sortHeight = height;
        sort(sortHeight.begin(),sortHeight.end());
        sortHeight.resize(unique(sortHeight.begin(),sortHeight.end())-sortHeight.begin());

        int res = 0;
        for(int s= 0;s<sortHeight.size();++s){
            auto splitHeight = sortHeight[s];
            if(splitHeight == 0){
                continue;
            }
            
            int heightDelta = (s==0?splitHeight: splitHeight - sortHeight[s-1]);

            int leftSide = -1;
            int possibleWidth = 0;

            int thisLevel = 0;

            for(int i=0;i< height.size();++i){

                if(height[i] < splitHeight){
                    if(leftSide == -1){
                        continue;
                    }else{
                        ++possibleWidth;
                        continue;
                    }
                }

                if(leftSide == -1){
                    leftSide = i;
                    continue;
                }else{
                    //this is right side
                    thisLevel += possibleWidth * heightDelta;
                    leftSide = i;
                    possibleWidth = 0;
                }
            }
            res += thisLevel;
        }
        return res;
    }
};

int main(){

    Solution s;
    {
        vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
        assert(s.trap(input) == 6);
    }
}
