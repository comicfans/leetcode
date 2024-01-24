#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return recConstruct(nums, 0, nums.size());
        
    }

    TreeNode* recConstruct(const vector<int>& nums, int begin, int end){
        if(begin == end){
            return nullptr;
        }

        int mid = (begin + end)/2;

        auto p = new TreeNode(nums[mid]);

        p->left = recConstruct(nums,begin,mid);
        p->right= recConstruct(nums,mid+1,end);
        return p;
    }
};

int main(){
    Solution s;
    {
        vector<int> input = {-10,-3,0,5,9};
        auto res = s.sortedArrayToBST(input);
    }
}
