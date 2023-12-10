#include <vector>
#include <cassert>
#include <sstream>
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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ret;



        string parent;

        recFill(root, ret,parent);
        return ret;
    }

    void recFill(TreeNode* root, vector<string>& ret, string& existing){

        if(!root){
            
            return;
        }

        string toPush;

        if(!existing.empty()){
            toPush = "->";
        }

        stringstream ss;
        ss<<root->val;
        string num;
        ss>> num;

        toPush = toPush + num;

        existing = existing+toPush;

        if(root->left){
            recFill(root->left, ret, existing);
        }

        if(root->right){
            recFill(root->right, ret, existing);
        }

        if(!root->left && !root->right){
            ret.push_back(existing);
        }

        existing.resize(existing.size() - toPush.size());
    }
};
