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
    int findTilt(TreeNode* root) {
        
        return sumAndTilt(root).second;
    }

    pair<int,int> sumAndTilt(TreeNode* root){
        if(!root){
            return {0, 0};
        }

        auto left = sumAndTilt(root->left);
        auto right = sumAndTilt(root->right);

        return {left.first + right.first + root->val, abs(left.first - right.first) + left.second + right.second};
    }
};
