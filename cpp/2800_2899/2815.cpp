#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {

        map<int, vector<int>> check;

        for(auto v:nums){
            int copy = v;

            int maxDigit = 0 ;
            while(v>0){

                maxDigit = max(maxDigit, v%10);
                v/=10;
            }

            auto pos = check.find(maxDigit);
            if(pos == check.end()){
                pos = check.insert({maxDigit,{}}).first;
            }

            auto& vec = pos->second;
            vec.push_back(copy);
            sort(vec.begin(),vec.end(),[](auto& lhs, auto& rhs){
                return lhs > rhs;
            });

            vec.resize(min<int>(vec.size(),2));
            
        }

        int ret = -1;
        for(auto &kv: check){

            if(kv.second.size() < 2){
                continue;
            }

            int thisSum = kv.second.front() + kv.second.back();
            ret = max(ret,thisSum);
        }
        return ret;
    }

};
