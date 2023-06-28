#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            if (nums.empty()) {
                return 0;
            }

            sort(nums.begin(),nums.end());

            return searchFor(nums,target,-1,1);
        }

        Solution(){
            found=false;
        }

    private:
        bool found;
        vector<int> result;

        int searchFor(const vector<int>& nums, int target,int lastIndex,int depth){
            if (depth==3) {

                vector<int>::const_iterator lower=lower_bound(nums.cbegin(),nums.cend(),target);

                lower=max(lower,nums.begin()+lastIndex+1);

                if (lower==nums.cend()) {
                    return *(lower-1);
                }

                if (lower-nums.begin()==lastIndex+1) {
                    return *lower;
                }

                int diff1=abs(*lower-target);
                int diff2=abs(*(lower-1)-target);

                if (diff1<diff2) {
                    return *lower;
                }else{
                    return *(lower-1);
                }

            }

            int prevResult;
            int prevDiff=numeric_limits<int>::max();
            for(int thisIdx=lastIndex+1;thisIdx < nums.size()-3+depth;++thisIdx ){
                int nextTarget=target-nums[thisIdx];
                int result=searchFor(nums,nextTarget,thisIdx,depth+1);
                int diff=abs(result-nextTarget);
                if (diff>prevDiff) {
                    continue;
                }

                prevDiff=diff;
                prevResult=nums[thisIdx]+result;
                if (prevDiff==0) {
                    return prevResult;
                }
            }

            return prevResult;
        }
};


int main(int argc, char *argv[])
{
    Solution s;
    int nums[]={-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};
    vector<int> input(nums,nums+sizeof(nums)/sizeof(int));
    
    cout<<s.threeSumClosest(input,0);
    cout<<endl;
    return 0;
}
