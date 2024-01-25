#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {


        const int width   = mat[0].size();
        const int height = mat.size();
        for(int x = 1; x < width;++x){

            int maxCount = min(min(width,height), width - x);

            vector<int> vec;
            vector<int*> ptr;
            for(int counter = 0;counter<maxCount;++counter){

                int thisX = x + counter;
                int thisY = counter;

                vec.push_back(mat[thisY][thisX]);
                ptr.push_back(&mat[thisY][thisX]);

            }

            sort(vec.begin(),vec.end());

            for(int i =0;i< vec.size();++i){
                *ptr[i] = vec[i];
            }
        }

        for(int y = 0; y < height; ++y){

            int maxCount = min(min(width,height), height - y);
            vector<int> vec;
            vector<int*> ptr;

            for(int counter = 0;counter < maxCount ; ++ counter){
                int thisX = counter;
                int thisY = y + counter;

                vec.push_back(mat[thisY][thisX]);
                ptr.push_back(&mat[thisY][thisX]);
            }

            sort(vec.begin(),vec.end());
            for(int i =0;i< vec.size();++i){
                *ptr[i] = vec[i];
            }
        }

        return mat;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
        vector<vector<int>> expect = {{1,1,1,1},{1,2,2,2},{1,2,3,3}};

        auto output = s.diagonalSort(mat);

        assert(output == expect);
    }
}
