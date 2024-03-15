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

        vector<Node*> level;
        if(root){
            level.push_back(root);
        }

        while(!level.empty()){
            vector<Node*> nextLevel;
            vector<int> thisLevel;
            for(auto p: level){
                if(!p){
                    continue;
                }
                thisLevel.push_back(p->val);
                for(auto c: p->children){
                    nextLevel.push_back(c);
                }
            }
            level.swap(nextLevel);
            ret.push_back(thisLevel);
        }

        return ret;

        
    }
};
