#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {

        if( k == 1){
            vector<int> ret;
            for(int i = 1; i<nums.size()-1;++i){
                ret.push_back(i);
            }
            return ret;
        }


        int decreaseBegin = -1;
        int decreaseEnd = -1;

        int increaseBegin = -1;
        int increaseEnd = -1;


        const int FIND_DECREASING = 0;
        const int FIND_INCREASING = 1;

        int state = FIND_DECREASING;

        vector<int> ret;

        for(int i = 0;i < nums.size(); ++i){


            if(i == 0){
                decreaseBegin = i;
                continue;
            }

            if(nums[i]< nums[i-1]){
                if(state == FIND_DECREASING){
                    decreaseEnd = i;
                    increaseBegin = -1;
                    increaseEnd = -1;
                    continue;
                }

                //find increasing, but invert, check enough

                if(increaseEnd-increaseBegin+1 >= k && decreaseEnd - decreaseBegin +1>= k){

                    int possible = max(min(decreaseEnd+1,increaseEnd- k)- max(increaseBegin-1,decreaseBegin + k)+1,0);
                    for(int i = 0;i<possible;++i){
                        ret.push_back(decreaseBegin+ k+i);
                    }

                }

                state = FIND_DECREASING;
                decreaseBegin = i-1;
                decreaseEnd = i;
                increaseBegin = -1;
                increaseEnd = -1;

                continue;
            }

            if(nums[i]>nums[i-1]){
                if(state == FIND_DECREASING){
                    //find decrease, but invert, test if decreasing is enough
                    if(decreaseEnd - decreaseBegin+1 < k){
                        state = FIND_DECREASING;
                        decreaseBegin = i;
                        decreaseEnd = i;
                        increaseBegin = -1;
                        increaseEnd = -1;
                        continue;
                    }

                    state = FIND_INCREASING;
                    if(increaseBegin == -1){
                        increaseBegin = i-1;
                    }
                    increaseEnd = i;
                    continue;
                }

                increaseEnd = i;
                continue;
            }


            // equal 

            assert(nums[i]==nums[i-1]);

            if(state == FIND_DECREASING){
                decreaseEnd = i;

                if(increaseBegin ==-1){
                    increaseBegin = i-1;
                    increaseEnd = i;
                }else{
                    increaseEnd = i;
                }
                
                continue;
            }

            
            increaseEnd = i;
        }

        if(increaseEnd != -1){
            //check enough
            if(increaseEnd - increaseBegin + 1>= k){

                    int possible = max(min(decreaseEnd+1,increaseEnd- k)- max(increaseBegin-1,decreaseBegin + k)+1,0);
                    for(int i = 0;i<possible;++i){
                        ret.push_back(decreaseBegin+ k+i);
                    }
            }
        }

        return ret;
        
    }
};

int main(){

    Solution s;
    {
        vector<int> input = {253747,459932,263592,354832,60715,408350,959296};
        auto res = s.goodIndices(input, 2);
        vector<int> expect = {3};
        assert(res == expect);

    }
    {
        vector<int> input = {478184,863008,716977,921182,182844,350527,541165,881224};
        auto res = s.goodIndices(input, 1);
        vector<int> expect = {1,2,3,4,5,6};
        assert(res == expect);
    }
    {
        vector<int> input = {878724,201541,179099,98437,35765,327555,475851,598885,849470,943442};
        auto res = s.goodIndices(input,4);
        vector<int> expect = {4,5};
        assert(res == expect);
    }
    {
        vector<int> input = {2,1,1,1,3,4,1};
        auto res = s.goodIndices(input,2);

        vector<int> expect {2,3};
        assert(res == expect);
    }
    {
        vector<int> input = {2,1,1,2};
        auto res = s.goodIndices(input,2);

        vector<int> expect {};
        assert(res == expect);

    }
    
}
