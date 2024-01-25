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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int leftDepth = numeric_limits<int>::max();
        if(root->left){
            leftDepth = minDepth(root->left);
        }
        int rightDepth = numeric_limits<int>::max();
        if(root->right){
            rightDepth = minDepth(root->right);
            
        }
        if(leftDepth == rightDepth && leftDepth == numeric_limits<int>::max()){
            return 1;
        }else{
            return 1+min(leftDepth,rightDepth);
        }
        
    }
};
