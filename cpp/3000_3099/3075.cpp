#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.begin(),happiness.end());

        long long ret = 0;

        for(int i = 0;i < k; ++i){
            //pick 
            //

            int thisV = happiness[happiness.size()-1-i];
            int after = thisV - i;
            if(after<0){
                break;
            }

            ret += after;


          
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {1,2,3};
        assert(s.maximumHappinessSum(input,2) == 4);
    }
    
    
    {
        vector<int> input = {2,3,4,5}; int k = 1;
        assert(s.maximumHappinessSum(input,1) == 5);
    }
    {
        vector<int> input = {12,1,42};
        assert(s.maximumHappinessSum(input,3) == 53);
    }
}
