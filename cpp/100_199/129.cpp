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
    int sumNumbers(TreeNode* root) {

        return recWalk(root,0);
        
    }
    
    int recWalk(TreeNode* root,int prev){
        if(!root){
            return 0;
        }

        int thisV = root->val + prev * 10;
        if(!root->left && !root->right){
            return thisV;
        }

        return recWalk(root->left,thisV) + recWalk(root->right,thisV);
    }
};
