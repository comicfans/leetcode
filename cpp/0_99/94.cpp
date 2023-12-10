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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<int> ret;

        vector<TreeNode*> stack = {root};

        while(!stack.empty()){

            while(stack.back()){
                if(stack.back()->left){
                    stack.push_back(stack.back()->left);
                }else if(stack.back()->right){
                    ret.push_back(stack.back()->val);
                    stack.push_back(stack.back()->right);
                }else{
                    break;
                }
            }

            ret.push_back(stack.back()->val);

            
            while(!stack.empty()){
                //pop until new nodes 
                auto walked = stack.back();
                stack.pop_back();
                if(stack.empty()){
                    break;
                }

                if(stack.back()->left == walked){
                    ret.push_back(stack.back()->val);

                    if(stack.back()->right){
                        stack.push_back(stack.back()->right);
                        break;
                    }else{
                        continue;
                    }
                }

                if(stack.back()->right == walked){
                    continue;
                }

            }
        }
        

        return ret;
    }

};

int main(){
    Solution s;
    {
        TreeNode n3(3);
        TreeNode n2(2,&n3,nullptr);
        TreeNode n1(1,nullptr,&n2);

        auto res = s.inorderTraversal(&n1);
        vector<int> expect = {1,3,2};
    }
}
