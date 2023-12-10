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
        map<int,int> thisUHeightCount;
        int leftMax = height[0];
        for(int i = 1;i<height.size();++i){


            if(height[i]>= height[i-1]){
                //do realize, or first

                int realizeHeight = min(leftMax, height[i]);

                vector<map<int,int>::iterator> toChange;
                int changeNumber = 0;
                for(auto it = thisUHeightCount.begin();it!= thisUHeightCount.end();++it){
                    auto kv = *it;
                    if(kv.first < realizeHeight){
                        toChange.push_back(it);
                        ret+= (realizeHeight - kv.first) * kv.second;
                        changeNumber += kv.second;
                    }
                }

                for(auto p : toChange){
                    thisUHeightCount.erase(p);
                }
                thisUHeightCount[realizeHeight]+= changeNumber;



                if(height[i] >= leftMax){
                    thisUHeightCount.clear();
                    leftMax = height[i];
                }else{
                    thisUHeightCount[height[i]]++;
                }
                continue;
            }

            thisUHeightCount[height[i]]++;
        }

        return ret;

    }

};

#include "parse.h"
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
