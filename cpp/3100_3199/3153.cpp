#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long oneDigit(const array<int,10>& digits,const int total){

        
        int left = total;
        long long ret = 0;
        for(int i = 0; i< digits.size(); ++i){

            left -= digits[i];
            long long thisContrubite = digits[i] * left;
            ret+= thisContrubite;
        }

        return ret;
    }
    long long sumDigitDifferences(vector<int>& nums) {


                
        long long ret = 0;
        while(nums.front()>0){
            array<int,10> digits{0};
            for(auto& v: nums){
                int dig = v% 10;
                v/=10;
                digits[dig]++;
            }

            long long thisRes = oneDigit(digits, nums.size());
            ret+= thisRes;
        }

        return ret;
    }


};

int main(){
    Solution s;
    {
        vector<int> input = {50,28,48};
        auto res = s.sumDigitDifferences(input);
        assert(res == 5);
    }
    {
        vector<int> input = {13,23,12};
        auto res = s.sumDigitDifferences(input);
        assert(res == 4);
    }
}
