#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {


        vector<int> minSum = triangle.back();

        for(int row = triangle.size()-2;row>=0;--row){

            vector<int> thisSum(row+1);
            for(int i = 0;i<= row; ++i){

                thisSum[i] = triangle[row][i]+ min(minSum[i],minSum[i+1]);
            }
            swap(minSum,thisSum);
        }
        

        return minSum.front();
    }

};
