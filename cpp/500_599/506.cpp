#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<pair<int,int> > order;
        for(int i = 0;i < score.size(); ++i){
            order.push_back({score[i],i});
        }

        sort(order.begin(),order.end(), [](const auto& lhs, const auto& rhs){
            return lhs > rhs;
        });

        
        vector<string> ret(order.size());
        for(int i = 0; i< order.size(); ++i){
            
            int idx = order[i].second;
            switch(i){
                case 0:{
                    ret[idx] = "Gold Medal";
                    break;
                };
                case 1:{
                    ret[idx] = "Silver Medal";
                    break;
                };
                case 2:{
                    ret[idx] = "Bronze Medal";
                    break;
                }
                default:{
                    ret[idx] = to_string(i+1);
                }
            }
        }

        return ret;

    }
};



int main(){
    Solution s;
    {
        vector<int> score = {10,3,8,9,4};
        auto res = s.findRelativeRanks(score);
        vector<string> expect = {"Gold Medal","5","Bronze Medal","Silver Medal","4"};
        assert(expect == res);
    }
}
