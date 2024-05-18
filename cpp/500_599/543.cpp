#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#ifdef LEETCODE

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        auto res = rec(root);
        
        return max(res.first, res.second);
    }

    pair<int,int> rec(TreeNode* root){

        if(!root){
            return {0,0};
        }

        pair<int,int> left = {0,0};
        if(root->left){
            left = rec(root->left);
        }

        pair<int,int> right = {0,0};
        if(root->right){
            right = rec(root->right);
        }

        //first is to root
        //second is cross root
        return {max(left.first,right.first)+1, max(max(left.second, right.second),left.first+right.first)};
    }
};
