#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> maxLength(nums.size());

        int isEven = -1;
        int currentLength = 0;

        for(int i = 0;i< nums.size(); ++i){
            auto v = nums[i];
            int thisIsEven = (v % 2 == 0);

            if((int)thisIsEven == isEven){

                isEven = thisIsEven;
                currentLength = 1;
                maxLength[i] = currentLength;
                continue;
            }
            isEven = thisIsEven;
            ++currentLength;
            maxLength[i] = currentLength;
        }

        vector<bool> ret(queries.size());

        for(int i = 0;i<queries.size(); ++i){
            const auto& q= queries[i];
            int begin = q[0];
            int end = q[1];
            int size = end - begin + 1;

            int possible = maxLength[end];
            ret[i] = (possible >= size);

        }
        return ret;

        
    }
};
int main(){
    Solution s;
    {
        vector<int> input = {3,4,1,2,6};
        vector<vector<int>> queries = {{0,4}};
        auto res = s.isArraySpecial(input,queries);
        vector<bool> expect = {false};
        assert(res == expect);
    }
}
