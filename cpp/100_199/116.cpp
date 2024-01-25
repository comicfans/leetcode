#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {

        vector<Node*> levels;

        if(!root){
            return root;
        }

        rec(root,levels, 0);
        
        return root;
    }
    void rec(Node* root, vector<Node*>& levels,int level){
        if(!root){
            return;
        }
        if(levels.size()<= level){
            levels.resize(level +1);
        }

        if(levels[level]){
            levels[level]->next = root;
        }
        levels[level] = root;
        root->next = nullptr;

        rec(root->left,levels,level+1);
        rec(root->right,levels,level+1);
        
    }
};

int main(){
    Solution s;{
        Node n4(4);
        Node n5(5);
        Node n6(6);
        Node n7(7);
        
        Node n2(2,&n4,&n5,0);
        Node n3(3,&n6,&n7,0);
        Node n1(1,&n2,&n3,0);

        s.connect(&n1);

        assert(!n1.next);
        assert(n2.next == &n3);
        assert(!n3.next);
        assert(n4.next == &n5);
        assert(n5.next == &n6);
        assert(n6.next == &n7);
        assert(!n7.next);
    }

}
