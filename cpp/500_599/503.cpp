#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> ret(nums.size(),INT_MAX);

        
        vector<int> peak;
        peak.reserve(nums.size());
        peak.push_back(0);
        for(int idx = 1; idx < nums.size(); ++idx){
            int v = nums[idx];


            if(v > nums[idx-1]){
                //fill back same value
                for(; !peak.empty() && nums[peak.back()] < v;){
                    int last = peak.back();
                    peak.pop_back();
                    if(ret[last]==INT_MAX){
                        ret[last] = v;
                    }
                }

                peak.push_back(idx);

                //if prev is less than nums[idx-1], thus no need to fill
                //if prev is > v, no need to fill?
                continue;
            }

            peak.push_back(idx);
        }

        if(peak.size() == nums.size()){
            ret[0] = -1;
            for(int i = 1; i< ret.size(); ++i){
                ret[i] = (nums.front() > nums[i]? nums.front(): -1);
            }

            return ret;
        }

        ret[peak.front()] = -1;
        int lessIdx = 1;
        for(; lessIdx < peak.size(); ++lessIdx){
            int thisI = peak[lessIdx];
            if(nums[thisI] == nums[peak.front()]){
                ret[thisI] = -1;
                continue;
            }
            break;
        }

        int peakIdx = peak.size() - 1;

        //now look for missed
        for(int j = 0; j < nums.size() && peakIdx >= lessIdx; ++j){
            
            
            for(int i = peak[peakIdx]; nums[j] > nums[i]; ){
                ret[i] = nums[j];
                if(peakIdx == lessIdx){
                    break;
                }
                --peakIdx;
                i = peak[peakIdx];
            }

            if(peakIdx == lessIdx && ret[peak[peakIdx]] != INT_MAX){
                break;
            }
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {100,1,11,1,120,111,123,1,-1,-100};
        vector<int> expect = {120,11,120,120,123,123,-1,100,100,100};
        auto res = s.nextGreaterElements(input);
        assert(expect == res);
    }
    {

        vector<int> input = {1,1,1,1,1};
        vector<int> expect = {-1,-1,-1,-1,-1};
        auto res = s.nextGreaterElements(input);
        assert(expect == res);
    }
    {

        vector<int> input = {1,2,3,2,1};
        vector<int> expect = {2,3,-1,3,2};
        auto res = s.nextGreaterElements(input);
        assert(expect == res);
    }
    {
        vector<int> input = {1,2,3,4,3};
        vector<int> expect = {2,3,4,-1,4};
        auto res = s.nextGreaterElements(input);
        assert(expect == res);

    }

    {
        vector<int> input = {1,2,1};
        vector<int> expect = {2,-1,2};
        auto res = s.nextGreaterElements(input);
        assert(expect == res);
    }

}
