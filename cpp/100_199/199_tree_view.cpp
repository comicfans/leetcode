
#include <vector>

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
    vector<int> rightSideView(TreeNode* root) {
        

        vector<int> ret;
        if(!root){
            return ret;
        }
        vector<TreeNode*> levels = {root};

        recVisit(levels, ret);
        
        return ret;
    }

    void recVisit(vector<TreeNode*>& levels, vector<int>& result){
        vector<TreeNode*> nextLevel;
        bool pushed = false;
        for(const auto n: levels){
            if(!pushed){
                result.push_back(n->val);
                pushed = true;
            }
            if(n->right){
                nextLevel.push_back(n->right);
            }
            if(n->left){
                nextLevel.push_back(n->left);
            }
        }

        swap(levels,nextLevel);

        if(levels.empty()){
            return;
        }

        recVisit(levels, result);
    }
};

int main(int, char**){
}
