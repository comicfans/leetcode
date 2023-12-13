#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        if(nums.front() == nums.back()){
            return 0;
        }

        int current = 0;

        for(int overFrom = 0; overFrom < nums.size(); ++overFrom){

            int thisCount = 0;
            int prevGreator = overFrom ;
            for(int j = overFrom; j < nums.size();++j){
                int thisV = nums[j];

                auto pos= upper_bound(nums.begin()+prevGreator+1,nums.end(),thisV) - nums.begin();

                if(pos == nums.size()){
                    break;
                }
                ++thisCount;
                prevGreator = pos;
            }

            if(thisCount < current){
                return current;
            }else{
                current = thisCount;
            }
        }
        

        return current;
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {1,2,3,4};
        assert(s.maximizeGreatness(input) == 3);
    }
    {
        vector<int> input = {1,3,5,2,1,3,1};
        assert(s.maximizeGreatness(input) == 4);
    }
    
}
