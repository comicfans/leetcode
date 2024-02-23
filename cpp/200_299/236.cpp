#ifdef LEETCODE
#include "../parse.h"
#endif


#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        auto res = walk(root,p,q,false);
        assert(res.first == 2);
        return res.second;
        
    }

    pair<int,TreeNode*> walk(TreeNode* root, TreeNode* p, TreeNode* q, bool parentFind){

        if(p == q){
            return {2,p};
        }

        if(!root){
            return {0,nullptr};
        }


        if(root == p || root == q){

            if(parentFind){
                return {1,root};
            }


            // no parent

            auto tryRight = walk(root->right, p,q,true);
            if(tryRight.second){
                return {2,root};
            }

            auto tryLeft = walk(root->left, p, q, true);
            if(tryLeft.second){
                return {2,root};
            }

            return {1,root};
        }

        auto tryLeft = walk(root->left,p,q,false);

        if(tryLeft.first == 2){
            return tryLeft;
        }

        auto tryRight = walk(root->right,p,q,false);
        if(tryRight.first == 2){
            return tryRight;
        }

        assert(tryLeft.first + tryRight.first <= 2);

        if(tryLeft.first + tryRight.first == 2){
            return {2,root};
        }

        return tryLeft.first > tryRight.first? tryLeft:tryRight;

        
    }
};


int main(){
    Solution s;
    {
        auto root = pt("[3,5,1,6,2,0,8,null,null,7,4]");

        auto res = s.lowestCommonAncestor(root.first.get(),
                                          root.first.get()->left,
                                          root.first.get()->right);
        assert(res == root.first.get());
    }
    {
        auto root = pt("[3,5,1,6,2,0,8,null,null,7,4]");

        auto res = s.lowestCommonAncestor(root.first.get(),root.second[1], root.second.back());
        assert(res == root.second[1]);
    }
    {
        auto root = pt("[1,2]");
        auto res = s.lowestCommonAncestor(root.first.get(),
                                          root.first.get(),
                                          root.first.get()->left);
        assert(res == root.first.get());

    }
}
