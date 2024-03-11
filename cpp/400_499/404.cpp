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

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        return rec(root, false);
        
    }

    int rec(TreeNode* root, bool isLeft){

        if(!root){
            return 0;
        }

        if(!root->left && !root->right && isLeft){
            return root->val;
        }

        int lSum = rec(root->left, true);
        int rSum = rec(root->right, false);

        return lSum + rSum;

    }
};
