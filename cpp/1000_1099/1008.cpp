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
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if(preorder.empty()){
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder.front());

        vector<pair<TreeNode*,bool>> chain = {{root,false}};

        recConstruct(chain, preorder, 1);

        return root;
    }

    void recConstruct(vector<pair<TreeNode*,bool>>& chain, const vector<int>& preorder, int pos){

        if(pos == preorder.size()){
            return;
        }

        int thisV = preorder[pos];

        if(thisV < chain.back().first->val){
            chain.back().first->left = new TreeNode(thisV);

            chain.push_back({chain.back().first->left,true});

            recConstruct(chain,preorder, pos + 1);
            return;
        }

        //thisV > prev, 
        //
        while(true){

            if(chain.size()==1){
                chain.back()->first.right = new TreeNode(thisV);

                chain.push_back({chain.back().first->right,false});
                recConstruct(chain, preorder, pos+1);
                return;
            }

            if(chain[chain.size()-2]->val > thisV){
                chain.back()->right = new TreeNode(thisV);
                chain.push_back(chain.back()->right);
                recConstruct(chain, preorder, pos + 1);
                return;
            }

            chain.pop_back();
        }
    }
};

int main(){
    Solution s;
    {
        vector<int> preorder = {8,5,1,7,10,12};
        auto res = s.bstFromPreorder(preorder);
    }
}
