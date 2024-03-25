#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int> ret;
        int totalSize = mat.size() * mat.front().size();

        ret.reserve(totalSize);

        int y = 0,x=0;
        int offset[][2] = {{-1,1},{1,-1}};

        int dir = 0;

        while(true){
            ret.push_back(mat[y][x]);


            int newY = y + offset[dir][0];
            int newX = x + offset[dir][1];

            if(newY >=0 && newY < mat.size() && newX >=0 && newX < mat.front().size()){
                y = newY;
                x = newX;
                continue;
            }

            if(dir == 0){

                if(newY < 0){
                    newY = 0;
                    newX = x+1;
                }

                if(newX == mat.front().size()){
                    newX = x;
                    newY = y + 1;
                }

                if(newY == mat.size() ){
                    break;
                }
                y = newY;
                x = newX;
                dir = 1;
                continue;
            }

            if(newX < 0){
                newX = x;
                newY = y+1;
            }

            if(newY == mat.size()){
                newY = y;
                newX = x+1;
            }

            if(newX == mat.front().size()){
                break;
            }

            y = newY;
            x= newX;
            dir = 0;
        }

        assert(ret.size() == totalSize);


        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> input = {{1}};
        vector<int> expect = {1};
        auto res = s.findDiagonalOrder(input);
        assert(res == expect);
    }
    {
        vector<vector<int>> input = {{1,2}};
        vector<int> expect = {1,2};
        auto res = s.findDiagonalOrder(input);
        assert(res == expect);
    }
    {
        vector<vector<int>> input = {{1},{2}};
        vector<int> expect = {1,2};
        auto res = s.findDiagonalOrder(input);
        assert(res == expect);
    }
    {
        vector<vector<int>> input = {{1,2},{3,4}};
        vector<int> expect = {1,2,3,4};
        auto res = s.findDiagonalOrder(input);
        assert(res == expect);
    }
    {
        vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
        vector<int> expect = {1,2,4,7,5,3,6,8,9};
        auto res = s.findDiagonalOrder(input);
        assert(res == expect);
    }
}
