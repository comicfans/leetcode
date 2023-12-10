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
    vector<int> findMode(TreeNode* root) {

        map<int,int> numberCount;

        recWalk(root,numberCount);

        
        vector<int> ret = {-1};
        int maxCount = 0;
        for(const auto& kv:numberCount){
            if(kv.second > maxCount){
                ret.clear();
                ret.push_back(kv.first);
                maxCount = kv.second;
            }else if(kv.second == maxCount){
                ret.push_back(kv.first);
            }
        }

        return ret;
        
    }

    void recWalk(TreeNode* root, map<int,int>& numberCount){
        if(!root){
            return;
        }

        numberCount[root->val]++;

        recWalk(root->left,numberCount);
        recWalk(root->right, numberCount);

    }
};
