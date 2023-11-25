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

        //throw from left, if is equal or greator

        int leftBegin = 0;
        for(int throwLeft = 1;throwLeft < height.size();++throwLeft){
            if(height[throwLeft]>= height[throwLeft - 1]){
                leftBegin = throwLeft;
            }else{
                break;
            }
        }

        auto end = height.erase(height.begin(),height.begin()+leftBegin);

        int rightEnd = height.size();
        //throw from right, if is equal or greator
        for(int throwRight = height.size()-2; throwRight >= 0;--throwRight){
            if(height[throwRight]> height[throwRight+1]){
                rightEnd = throwRight+1;
            }else{
                break;
            }
        }
        height.resize(rightEnd);


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
        vector<int> input = {9,6,8,8,5,6,3};
        s.trap(input);
    }
    {
        vector<int> input = {0,7,1,4,6};
        assert(s.trap(input) == 7);
    }
    {
        vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
        assert(s.trap(input) == 6);
    }
    
    
}
