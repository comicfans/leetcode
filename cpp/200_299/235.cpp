#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#ifndef TreeNode 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
#endif

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> toP;
        vector<TreeNode*> toQ;

        walk(root,p,toP);
        walk(root,q,toQ);

        int compareEnd = min(toP.size(),toQ.size());
        for(int i = compareEnd-1; i>= 0 ;--i){
            if(toP[i] == toQ[i]){
                return toP[i];
            }
        }
        
        return nullptr;
    }

    void walk(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(!root){
            return;
        }

        path.push_back(root);

        if(root == target){
            return;
        }



        if(root->val < target->val){
            walk(root->right,target,path);
        }else{
            walk(root->left,target,path);
        }
    }
};
