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

        if(height.size() < 3){
            return 0;
        }

        int ret = 0;
        multiset<int> thisUHeights;
        int leftMax = height[0];
        for(int i = 1;i<height.size();++i){


            if(height[i]>= height[i-1]){
                //do realize, or first

                int realizeHeight = min(leftMax, height[i]);

                vector<multiset<int>::iterator> toChange;
                for(auto it = thisUHeights.begin();it!= thisUHeights.end();++it){
                    auto h = *it;
                    if(h<= realizeHeight){
                        toChange.push_back(it);
                        ret+= realizeHeight - h;
                    }
                }

                for(auto p : toChange){
                    thisUHeights.erase(p);
                }
                for(int i=0;i< toChange.size();++i){
                    thisUHeights.insert(realizeHeight);
                }



                if(height[i] >= leftMax){
                    thisUHeights.clear();
                    leftMax = height[i];
                }else{
                    thisUHeights.insert(height[i]);
                }
                continue;
            }

            thisUHeights.insert(height[i]);
        }

        return ret;

    }

};

#include "parse.h"
int main(){

    Solution s;
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
