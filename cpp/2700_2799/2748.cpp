#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ret = 0;

        for(int begin = 0;begin < nums.size()-1;++begin){
            for(int end = begin +1; end < nums.size();++end){

                int begin_number = nums[begin];

                while(begin_number >= 10){
                    begin_number = begin_number / 10;
                }

                int end_number = nums[end]%10;


                int try_gcd = min(begin_number, end_number);

                while(try_gcd != 1){
                    int reminder = max(begin_number, end_number) % try_gcd;

                    if(reminder == 0){
                        break;
                    }

                    begin_number = min(begin_number, end_number);
                    end_number = try_gcd;
                    try_gcd = reminder;
                }

                if(try_gcd != 1){
                    cout<<nums[begin]<<"_"<<nums[end]<<endl;
                }

                ret+=(try_gcd == 1);
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    //vector<int> nums = {2,5,1,4};
    //cout << s.countBeautifulPairs(nums) << endl;
    //nums = {11,21,12};
    //cout << s.countBeautifulPairs(nums) << endl;
    //nums = {31,25,72,79,74};
    //cout << s.countBeautifulPairs(nums) << endl;

    vector<int> nums = {756,1324,2419,495,106,111,1649,1474,2001,1633,273,1804,2102,1782,705,1529,1761,1613,111,186,412};
    cout << s.countBeautifulPairs(nums) << endl;
    return 0;
}
