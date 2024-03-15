#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#ifdef LEETCODE
#include "../parse.h"
#endif

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {

        vector<int64_t> cumsum;

        return rec(root, targetSum, cumsum);
        
    }

    int rec(TreeNode* root, const int targetSum, vector<int64_t>& cumsum){
        if(!root){
            return 0;
        }

        cumsum.push_back(cumsum.empty()? root->val: cumsum.back() + root->val);

        
        int upToThis = 0;
        for(int from = 0; from < cumsum.size(); ++from){
            auto thisSum = cumsum.back() - (from ==0 ? 0: cumsum[from - 1]);
            if(thisSum == targetSum){
                ++upToThis;
            }
        }

        int leftPossible = rec(root->left, targetSum, cumsum);
        int rightPossible = rec(root->right, targetSum, cumsum);

        int ret = upToThis + leftPossible + rightPossible;

        cumsum.pop_back();
        return ret;
        
    }
};

int main(){
    Solution s;
    {
        auto tree = pt("[1000000000,1000000000,null,294967296,null,1000000000,null,1000000000,null,1000000000]");

        auto res = s.pathSum(tree.first.get(), 0);
        assert(res == 0);
    }
}
