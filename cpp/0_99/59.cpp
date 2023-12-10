#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ret(n);
        for(auto& row:ret){
            row.resize(n,-1);
        }

        int yx[2]={0,0};

        int offset[][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        int currentOff= 0;

        int counter = 1;
        int limit = n*n;
        while(counter <= limit){

            if(yx[0]<0 || yx[1] < 0 || yx[0]>=n || yx[1]>=n || ret[yx[0]][yx[1]]!=-1){
                //revert last step
                yx[0] -= offset[currentOff][0];
                yx[1] -= offset[currentOff][1];
                currentOff = (currentOff + 1) % 4;

                yx[0]+= offset[currentOff][0];
                yx[1]+= offset[currentOff][1];
                continue;
            }

                ret[yx[0]][yx[1]] = counter;
                yx[0]+= offset[currentOff][0];
                yx[1]+= offset[currentOff][1];
                ++counter;
        }

        return ret;
    }
};

int main(
){
    Solution s;
    {
        auto ret = s.generateMatrix(3);

        return 3;
    }

}
