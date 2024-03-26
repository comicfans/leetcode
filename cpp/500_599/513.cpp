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

        vector<TreeNode*> level = {root};


        while(!level.empty()){

            int res = level.front()->val;
            vector<TreeNode*> next;
            for(auto p: level){
                if(p->left){
                    next.push_back(p->left);
                }
                if(p->right){
                    next.push_back(p->right);
                }
            }

            if(next.empty()){
                break;
            }

            swap(next, level);
        }

        return res;
    }

    
};
