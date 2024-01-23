#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() ==1){
            return nums.front()==target;
        }
        
        int head = findHead(nums, 0, nums.size()-1);

        bool inLeft = binary_search(nums.begin(),nums.begin()+head,target);
        if(inLeft){
            return true;
        }

        return binary_search(nums.begin()+head,nums.end(),target);

    }

    int findHead(const vector<int>& nums,const int left, const int right){

        for(int i = left+1; i<= right;++i){
            if(nums[i] < nums[i-1]){
                return i;
            }
        }

        return 0;
       
    }
};

int main(){
    Solution s;

    {
        vector<int> nums={1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};

        auto head = s.findHead(nums,0,nums.size()-1);
        assert(head == 14);
        assert(s.search(nums,2));
    }
    {
        vector<int> nums={2,2,2,3,2,2,2};
        auto head = s.findHead(nums,0,nums.size()-1);
        assert(head == 4);
        assert(s.search(nums,3));
    }
    {
        vector<int> nums = {2,5,6,0,0,1,2};

        auto head = s.findHead(nums,0,nums.size()-1);
        assert(head == 3);
    }
    {
        vector<int> nums = {2,2,5,6,0,0,1};

        auto head = s.findHead(nums,0,nums.size()-1);
        assert(head == 4);
    }
    {
        vector<int> nums = {1,2,2,5,6,0,0};

        auto head = s.findHead(nums,0,nums.size()-1);
        assert(head == 5);
    }
    {
        vector<int> nums = {0,1,2,2,5,6,0};

        auto head = s.findHead(nums,0,nums.size()-1);
        assert(head == 6);
    }
    
}
