#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret = {{1}};

        for(int i = 1; i < numRows; ++i){
            vector<int> thisRow = ret.back();
            
            thisRow.push_back(1);
            for(int j = 1;j<i;++j){
                thisRow[j] = ret.back()[j-1] + thisRow[j];
            }
            ret.push_back(thisRow);
        }
        return ret;
    }
};

int main(){
    Solution s;
    {
        auto res = s.generate(5);

        assert(res[0]==vector<int>{1});
        assert(res[1]==(vector<int>{1,1}));
        assert(res[2]==(vector<int>{1,2,1}));
        assert(res[3]==(vector<int>{1,3,3,1}));
        assert(res[4]==(vector<int>{1,4,6,4,1}));
    }
}
