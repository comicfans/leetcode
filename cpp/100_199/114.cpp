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
    void flatten(TreeNode* root) {
        
        if(!root){
            return; 
        }
        TreeNode** tail = &root;
        rec(root,tail);
        (*tail)->right = nullptr;
    }
    void rec(TreeNode* current,TreeNode** tail){
        TreeNode* right = current->right;
        if(current->left){

            current->right = current->left;
            current->left = nullptr;
            tail = &current->right;
            rec(*tail, tail);
        }

        (*tail)->right = current;
        tail = &current;

        

        if(right){
            
            (*tail)->right = right;
            rec(right, tail);
            right->left = nullptr;
        }
    }
};

int main(){
    Solution s;
    {
        TreeNode n3(3);
        TreeNode n4(4);
        TreeNode n2(2,&n3,&n4);
        TreeNode n6(6);
        TreeNode n5(5,0,&n6);
        TreeNode n1(1,&n2,&n5);

        s.flatten(&n1);
        vector<int> expect = {1,2,3,4,5,6};
        auto p = &n1;
        for(int i = 0;i<expect.size();++i){
            assert(expect[i]== p->val);
            assert(!p->left);
            p =p->right;
        }
        assert(!p);
    }

}
