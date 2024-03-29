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
    int trap(vector<int>& height) {
        vector<int> cummax(height.size());

        int prev = 0;
        for(int i = 0;i < height.size(); ++i){
            cummax[i] = max(prev, height[i]);
            prev = cummax[i];
        }

        int ret = 0;

        int rightCummax = height.back();
        for(int i = 1;i< height.size()-1; ++i){

            int leftHeight = cummax[height.size() - 1 -i];
            int rightHeight = rightCummax;

            int minHeight = min(leftHeight, rightHeight);

            int delta = max(minHeight  - height[height.size()-1-i],0);

            ret+=delta;
            rightCummax = max(rightCummax, height[height.size()-1-i]);
        }

        return ret;

    }

};

#ifdef LEETCODE
#include "../parse.h"
int main(){

    Solution s;
    {
        vector<int> input = {4,2,0,3,2,5};
        assert(s.trap(input) == 9);
    }
    {
        auto input = pvi("42_case1.txt",0);
        s.trap(input);
    }
    {
        vector<int> input = {0,7,1,4,6};
        assert(s.trap(input) == 7);
    }
    {
        vector<int> input = {9,6,8,8,5,6,3};
        s.trap(input);
    }
    
    {
        vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
        assert(s.trap(input) == 6);
    }

    
    
}
#endif
