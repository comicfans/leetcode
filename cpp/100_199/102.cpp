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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        recFill(root,ret,0);
        return ret;
    }

    void recFill(TreeNode* r,vector<vector<int>>& ret,int level){
        if(!r){
            return;
        }
        if(ret.size()<=level){
            ret.resize(level+1);
        }
        ret[level].push_back(r->val);
        recFill(r->left,ret,level+1);


        recFill(r->right,ret,level+1);
    }
};
