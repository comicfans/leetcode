#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
/*
// Definition for a Node.
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
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        int subMax = 0;
        for(auto s: root->children){
            int thisS = maxDepth(s);
            subMax=  max(subMax,thisS); 
        }
        return subMax+1;
    }
};
