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
    bool isBalanced(TreeNode* root) {
        auto res = recIs(root);
        return res!=-1;
    }

    int recIs(TreeNode* root){
        if(!root){
            return 0;
        }

        int leftD = recIs(root->left);
        if(leftD<0){
            return -1;
        }
        int rightD = recIs(root->right);
        if(rightD <0){
            return -1;
        }
        if(abs(leftD-rightD)>1){
            return -1;
        }
        return 1+ max(leftD,rightD);
    }
};
