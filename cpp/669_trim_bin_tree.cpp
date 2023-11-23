#include <iostream>
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return recTrim(root, low, high);
    }

    TreeNode* recTrim(TreeNode *root, int low, int high){

        if(root == nullptr){
            return nullptr;
        }

        if(root->val == low){
            root->left = nullptr;
            root->right = recTrim(root->right, low,high);
            return root;
        }

        if(root->val < low){
            return recTrim(root->right, low, high);
        }

        if(root->val == high){
            root->right = nullptr;
            root->left = recTrim(root->left, low, high);
            return root;
        }

        if(root->val > high){
            return recTrim(root->left, low,high);
        }

        root->left = recTrim(root->left, low,high);
        root->right= recTrim(root->right, low,high);
        return root;

    }

    void recPrint(TreeNode* root, int level = 0){
        if(!root){
            return;
        }

        cout<<level<<root->val<<endl;
        recPrint(root->left, level+1);
        recPrint(root->right, level+1);
    }
};

int main(){
    Solution s;
    {
    }
}


