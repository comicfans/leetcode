#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {

        

        int ret = 0;
        int lastLeft = 0;
        int lastRight = 0;

        for(int i = 0;i < height.size();++i){
            int left = height[i];
            if(left <= lastLeft){
                continue;
            }

            for(int j = i+1;j < height.size();++j){
                int right = height[j];

                int thisArea = min(left,right) * (j - i);
                if(thisArea > ret){
                    lastLeft = left;
                    lastRight = right;
                }
                ret = max(ret, thisArea);
            }
        }
        return ret;
        
    }
};

#include "parse.h"
int main(){

    Solution s;
    {
        vector<int>height = {1,8,6,2,5,4,8,3,7};
        assert(s.maxArea(height) ==49);
    }
    {
        auto height = pvi("10_case1.txt", 0);

        s.maxArea(height);

    }
}
