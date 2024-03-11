#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
//[4,4][5,0][5,2][6,1][7,0][7,1]
//                    [4,4]
//[5,0]    
//
//          [5,2]
//               [6,1]
//      [7,0]
//                        [7,1]
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto& lhs, const auto& rhs ){
            return pair<int,int>(lhs[0],lhs[1]) < pair<int,int>(rhs[0],rhs[1]);
        });

        vector<vector<int>> ret(people.size(), vector<int>{-1});

        for(int pos = 0; pos < people.size(); ++pos){
            const auto& p = people[pos];

            int empty = 0;
            for(int check = 0; check < people.size(); ++check){
                if(ret[check][0] != -1){
                    if(ret[check][0] < p[0]){
                        continue;
                    }else{
                        ++empty;
                        continue;
                    }
                }
                if(empty == p[1]){
                    ret[check] = p;
                    break;
                }
                ++empty;
            }
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        vector<vector<int>> expect = {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}};
        auto res = s.reconstructQueue(people);
        assert(res == expect);

    }
}
