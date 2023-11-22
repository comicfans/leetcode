#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        vector<int> ret;

        int maxWidth = 0;
        //first from 0 to nums.size()
        //
        for(int y = 0;y <nums.size(); ++y){
            maxWidth = max(maxWidth, (int)nums[y].size());

            for(int x = 0; x <= y;++x){
                int thisY = y - x;
                if(x < nums[thisY].size()){
                    ret.push_back(nums[thisY][x]);
                }
            }
        }

        for(int x=1; x < maxWidth;++x){

            for(int y = nums.size()-1;y >=0; --y){
                int thisX = (nums.size() - 1 -y) + x;
                if(thisX< nums[y].size()){
                    ret.push_back(nums[y][thisX]);
                }
                if(thisX >= maxWidth){
                    break;
                }
            }
        }

        return ret;

        
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
        vector<int> expect = {1,4,2,7,5,3,8,6,9};
        auto res = s.findDiagonalOrder(nums);
        assert(res == expect);

    }
    {
        vector<vector<int>> nums=  {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
        vector<int> expect = {1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16};
        auto res = s.findDiagonalOrder(nums);
        assert(res == expect);
    }
}
