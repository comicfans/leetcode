#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        auto res = rec(root, 0);

        return res.second;
    }

    pair<int,int> rec(TreeNode* root, int level){

        assert(root);


        if(!root->left && !root->right){
            return {level, root->val};
        }

        pair<int,int> right = {-1, 0};
        if(root->right){
            right = rec(root->right, level+1);
        }

        pair<int,int> left = {-1,0};
        if(root->left){
            left = rec(root->left, level+1);
        }


        if(left.first >= right.first){
            return left;
        }

        return right;

    }
};
