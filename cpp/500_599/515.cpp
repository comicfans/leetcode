#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#ifdef LEETCODE
#include "../parse.h"
#endif

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
    vector<int> largestValues(TreeNode* root) {

        vector<int> ret;

        rec(root, ret, 0);

        return ret;
    }

    void rec(TreeNode* root, vector<int>& ret, int level ){
        if(!root){
            return;
        }
        if(ret.size() <= level){
            ret.resize(level+1);
            ret.back() = root->val;
        }else{
            ret[level] = max(ret[level], root->val);
        }

        rec(root->left, ret, level+1);
        rec(root->right, ret, level+1);

    }
};
