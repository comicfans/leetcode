#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {

        return nums[recFind(nums,0, nums.size()-1)];
        
    }

    int recFind(const vector<int>& nums,int begin ,int end){

        if(nums[begin] < nums[end]){
            return begin;
        }

        if(end - begin<= 1){
            return end;
        }

        int mid = (begin+end)/2;

        int midValue = nums[mid];

        if(midValue < nums[end]){
            return recFind(nums,begin, mid);
        }

        return recFind(nums,mid, end);



    }
};
