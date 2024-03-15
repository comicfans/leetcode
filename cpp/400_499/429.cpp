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

        int level = 0;

        while(rec(ret, root, level, 0)){
            ++level;
        }

        return ret;
    }

    bool rec(vector<vector<int>> &ret, Node* root, int level, int current){

        assert(level >= current);

        if(!root){
            return false;
        }

        if(level == current){
            if((int)ret.size()<level+1){
                assert((int)ret.size() == level );
                ret.resize(ret.size()+1);
            }

            ret.back().push_back(root->val);
            return true;
        }

        bool atLeastOne = false;
        for(auto p: root->children){
            atLeastOne |= rec(ret, p, level, current+1);
        }

        return atLeastOne;
    }
};
