#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        sort(nums.begin(),nums.end());

        for(int i =0; i< nums.size();++i){

            const auto& s = nums[i];
            int value = 0;

            int weight = 1;
            for(int b = 0; b< nums.size(); ++b){
                value  += (s[nums.size() -1- b]- '0')*weight;
                weight *= 2;
            }

            if(value != i){
                string  ret ;

                while(i!=0){
                    ret.push_back(i%2 + '0');
                    i/=2;
                }

                ret.resize(nums.size(),'0');

                reverse(ret.begin(),ret.end());
                return ret;
            }
        }

        string ret ;
        int i = nums.size();
        while(i!=0){
                    ret.push_back(i%2 + '0');
                    i/=2;
        }
        
        ret.resize(nums.size(),'0');
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<string> input = {"01","10"};
        auto res = s.findDifferentBinaryString(input);
    }
}
