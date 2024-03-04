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


struct Res{
    int rob;
    int notRob;
};

class Solution {
public:
    int rob(TreeNode* root) {

        auto res = rec(root);
        return max(res.rob, res.notRob);
    }

    Res rec(TreeNode* root){

        if(!root){
            return {0,0};
        }

        auto left = rec(root->left);
        auto right = rec(root->right);

        int robThis = root->val + left.notRob + right.notRob;

        int notRobThis = max(left.rob,left.notRob) + max(right.rob, right.notRob);

        return {robThis, notRobThis};

    }
};

int main(){
    Solution s;
    {
        auto tree = pt("[3,2,3,null,3,null,1]");
        assert(s.rob(tree.first.get()) == 7);
    }
}
