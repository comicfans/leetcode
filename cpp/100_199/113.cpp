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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ret;


        vector<int> existing;
        recFind(root,targetSum, ret,existing);

        return ret;
    }


    void recFind(TreeNode* n, int target, vector<vector<int>>& ret,vector<int>& existing){

        if(!n){
            return;
        }

        int left = target - n->val;

        existing.push_back(n->val);



        bool isLeaf = !n->left && !n->right;

        if(isLeaf ){

            if(left == 0 ){
                ret.push_back(existing);
            }
                existing.pop_back();
            return;
        }


        recFind(n->left, left, ret, existing);
        recFind(n->right, left, ret, existing);
        existing.pop_back();
    }

};

int main(){
    Solution s;
    {
        TreeNode p2(2);
        TreeNode p11(11,&p2,nullptr);
        TreeNode p4(4,&p11,nullptr);
        TreeNode p5(5,&p4,nullptr);

        auto res = s.pathSum(&p5, 22);
    }
}
