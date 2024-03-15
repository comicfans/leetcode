#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#ifdef LEETCODE 
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
#endif

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> ret;


        rec(ret, root, 0);

        return ret;
    }

    void rec(vector<vector<int>> &ret, Node* root, int current){

        if(!root){
            return ;
        }

        if(ret.size() < current+1){
            ret.resize(current+1);
        }

        ret[current].push_back(root->val);
        for(auto c: root->children){
            rec(ret,c,current+1);
        }
    }
};
