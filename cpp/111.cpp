#include <limits>
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

        return recFind(root,1);
    }

    int recFind(TreeNode* root, int level){

        if(!root->left && !root->right){
            return level;
        }

        int left = numeric_limits<int>::max();
        if (root->left){
            left = recFind(root->left, level+1);
        }

        int right  = numeric_limits<int>::max();

        if(root->right){
            right = recFind(root->right, level+1);
        }

        return min(left,right);
    }
};
