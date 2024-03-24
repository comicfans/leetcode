#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {

        map<int,long long> numCount;
        multimap<long long,int> countNum;

        vector<long long> ret(nums.size());

        for(int i = 0;i<nums.size(); ++i){

            int n = nums[i];
            int f = freq[i];

            auto pos = numCount.find(n);
            if(pos==numCount.end()){
                numCount[n] = f;
                countNum.insert({f,n});
                auto big = countNum.end();
                --big;
                ret[i] = big->first;
                continue;
            }

            long long &oldCount = pos->second;

            auto p = countNum.equal_range(oldCount);

            for(auto it = p.first; it!= p.second; ++it){
                if(it->second == n){
                    countNum.erase(it);
                    break;
                }
            }

            long long newCount = oldCount + f;
            oldCount = newCount;
            countNum.insert({newCount, n});
            auto big = countNum.end();
            --big;
            ret[i] = big->first;
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> num = {2,3,2,1};
        vector<int> freq = {3,2,-3,1};
        vector<long long> expect = {3,3,2,2};
        auto res = s.mostFrequentIDs(num,freq);
        assert(res == expect);
    }
}
