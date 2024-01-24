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
    bool isValidBST(TreeNode* root) {

        vector<int> chain;
        return recCheck(root, numeric_limits<int>::min(),numeric_limits<int>::max());
        
    }

    bool recCheck(TreeNode* root, int min, int max){
        if(!root){
            return true;
        }

        if(root->val < min || root->val > max){
            return false;
        }
        

        if(root->left) {
            if(root->val == numeric_limits<int>::min()){
                return false;
            }

            bool left = recCheck(root->left, min, root->val - 1);
            if(!left){
                return false;
            }
        }

            

        

        if(root->right){
            if(root->val == numeric_limits<int>::max()){
                return false;
            }
            bool right = recCheck(root->right,root->val+1, max);
            if(!right){
                return false;
            }
        }
        

        return true;
    }
};

int main(){
}
