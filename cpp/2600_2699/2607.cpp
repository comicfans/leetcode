#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        if(arr.empty()){
            return 0;
        }
        

        vector<bool> offsets(k,0);

        vector<vector<int>> loops;

        for(int start = 0; start < k; ++start){

            if(offsets[start]){
                continue;
            }

            vector<int> loop;

            int i = start;

            while(true){
                offsets[i] = true;
                for(;i < arr.size(); i+= k){
                    auto v= arr[i];
                    loop.push_back(v);
                }

                i = i % arr.size();
                if(offsets[i]){
                    break;
                }
            }
            loops.push_back(loop);
        }

        //for every loop, find mean
        //
        //
        //
        //
        // 2,9,10
        //
        // sum (abs(xn - v))

        long long ret = 0;
        for(auto& array: loops){

            sort(array.begin(),array.end());




        }
        return ret;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> arr = {1,4,1,3};
        int k = 2;
        assert(s.makeSubKSumEqual(arr,k) == 1);
    }
    {
        vector<int> arr = {2,5,5,7};int  k = 3;

        assert(s.makeSubKSumEqual(arr,k) == 5);
    }
    {
        vector<int> arr = {2,10,9};
        int k = 1;
        assert(s.makeSubKSumEqual(arr,k)== 8);
    }
}
