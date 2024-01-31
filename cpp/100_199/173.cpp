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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {

        virtualRoot.val =  numeric_limits<int>::min();
        virtualRoot.right = root;
        chain.push_back(&virtualRoot);
    }

    TreeNode virtualRoot;

    vector<TreeNode*> chain;

    bool eof = false;
    
    int next() {
        // walk to next ele

        if(!chain.back()->right){
        
            int current = chain.back()->val;
            while(chain.back()->val <= current){
                chain.pop_back();
            }


            return chain.back()->val;
        }

        auto p = chain.back()->right;
        while(p){
            chain.push_back(p);
            p=p->left;
        }

        return chain.back()->val;
        
    }
    
    bool hasNext() {
        if(chain.back()->right){
            return true;
        }

        for(auto v: chain){
            if(v->val > chain.back()->val){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(){

    {
        TreeNode n3(3);
        TreeNode n9(9);
        TreeNode n20(20);
        TreeNode n15(15,&n9,&n20);
        TreeNode n7(7,&n3,&n15);

        BSTIterator iter(&n7);
        assert(iter.hasNext());
        assert(iter.next()==3);
        assert(iter.hasNext());
        assert(iter.next()==7);
        assert(iter.hasNext());
        assert(iter.next()==9);
        assert(iter.hasNext());
        assert(iter.next()==15);
        assert(iter.hasNext());
        assert(iter.next()==20);
        assert(!iter.hasNext());

    }
}
