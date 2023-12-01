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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    if(!root|| ! target){
        return {};
    }
        

        vector<TreeNode*> parentChain;

        vector<int> ret;
        recFind(root, target,parentChain,  k, ret);

        return ret;

    }

    void recWalk(TreeNode* root, TreeNode* walked, int leftK, vector<int>& ret){
        if(!root){return;}

        if(root == walked){
            return;
        }
        

        assert(leftK >= 0);
        if(leftK == 0){
            ret.push_back(root->val);
            return;
        }

        recWalk(root->left, walked, leftK -1 ,ret);
        recWalk(root->right, walked, leftK -1 ,ret);
    }

    bool recFind(TreeNode* root, TreeNode* target, vector<TreeNode*>&parentChain, int k, vector<int>& ret){
        if(!root){
            return false;
        }

        parentChain.push_back(root);

        if(root == target){
            //found

            for(auto leaf = 0; leaf < parentChain.size();++leaf){

                int leftK = k - leaf;
                if(leftK < 0){
                    break;
                }

                recWalk(parentChain[parentChain.size()-1-leaf], leaf==0?nullptr: parentChain[parentChain.size()-leaf],leftK,ret);
            }

            return true;
        }


        bool inLeft = recFind(root->left, target,parentChain, k ,ret);

        if(inLeft){
            return true;
        }

        bool inRgith = recFind(root->right, target,parentChain,k,ret);
        if(inRgith){
            return true;
        }


        parentChain.pop_back();
        return false;
    }
};
int main(){
}
