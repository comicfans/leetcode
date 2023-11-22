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

        int maxWidth = 0 ;
        for(const auto& v : nums){
            maxWidth = max(maxWidth, (int)v.size());
        }

        //    a= 0   1
        //    db =   2
        //    gec =  3
        //    hf =   2
        //    i =    1
        //     
        //    a  b  c
        //    d  e  f
        //    g  h  i
        //
        int height = nums.size();

        int minSize=  min(maxWidth, (int)nums.size());
        int maxSize=  max(maxWidth, (int)nums.size());


        map<int,int> m;
        for(int y =0;y < nums.size(); ++y){

            for(int x = 0; x< nums[y].size(); ++x){

                int thisIdx = -1;
                if(x+y < minSize-1){

                    int prevTotal = (1+(x+y)) * (x+y) /2 ;
                    thisIdx = prevTotal+ x;
                    
                }else{

                    //for < min part, 
                    int triangleSize = (minSize - 1) * minSize / 2;
                    if(x + y >= maxSize){
                        int centerSize = (maxSize - minSize+1 ) * minSize;

                        int thisPartLong = minSize - 1;
                        int n = x + y - maxSize;
                        int thisPartShort = (minSize - 1) - n+1;
                        int thisPart = (thisPartLong + thisPartShort) * n / 2;

                        thisIdx = triangleSize + centerSize + thisPart + height - y - 1;
                    }else{
                        int centerSize = (x+y+1-minSize) * minSize;
                        thisIdx = triangleSize + centerSize + min(x, height - y  - 1) ;
                    }
                }


                


                m[thisIdx] = nums[y][x];
            }
        }

        vector<int> nonZero;
        for(auto &kv: m){
            nonZero.push_back(kv.second);
        }
        

        return nonZero;
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
    {
        vector<vector<int>> nums = {{1,2,3},{4},{5,6,7},{8},{9,10,11}};
        vector<int> expect = {1,4,2,5,3,8,6,9,7,10,11};

        auto res = s.findDiagonalOrder(nums);
        assert(res == expect);
    }
    {

        vector<vector<int>> nums= {{6,19,1,16,9},{9,13,4,8,19},{8,18,11,20,18},{9,9,15,12}};
        vector<int> expect = {6,9,19,8,13,1,9,18,4,16,9,11,8,9,15,20,19,12,18};
        auto res = s.findDiagonalOrder(nums);
        assert(res == expect);
    }
}
