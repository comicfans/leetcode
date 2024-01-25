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

struct Res{
    int singlePath;
    int withoutRoot;
    int maxLeaf;
};


    int maxPathSum(TreeNode* root) {
        

        auto res = recFind(root);

        if(res.maxLeaf < 0){
            return res.maxLeaf;
        }

        return max(res.singlePath,res.withoutRoot);

    }

    Res recFind(TreeNode* root){

        if(!root){
            return {
                .singlePath = 0,
                .withoutRoot = 0,
                .maxLeaf = numeric_limits<int>::min()
            };
        }

        auto left = recFind(root->left);
        auto right = recFind(root->right);

        int singlePath = root->val;
        singlePath = max(singlePath, root->val + left.singlePath);
        singlePath = max(singlePath, root->val + right.singlePath);

        int fromLeftToRight = left.singlePath + root->val+right.singlePath ;

        int withoutRoot = max(left.withoutRoot,right.withoutRoot);
        withoutRoot = max(withoutRoot, left.singlePath);
        withoutRoot = max(withoutRoot, right.singlePath);

        int maxLeaf = max(left.maxLeaf,right.maxLeaf);
        maxLeaf = max(maxLeaf, root->val);

        return {singlePath, max(withoutRoot,fromLeftToRight), maxLeaf};
    }
};

int main(){
    Solution s;
    {
        TreeNode n61(-6);
        TreeNode n3(-3);
        TreeNode n62(-6);
        TreeNode n2(-2,&n61,nullptr);
        TreeNode n10(10,&n3,&n62);
        TreeNode n1(-1,&n2,&n10);
        auto res = s.maxPathSum(&n1);

        assert(res == 10);
    }
}

