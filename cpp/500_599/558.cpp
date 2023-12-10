#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        auto ret = rec(quadTree1,quadTree2);

        return ret.first;
    }

    pair<Node*,int> rec(Node* left, Node* right){

        if(!left){
            return {right,right->val};
        }

        if(!right){
            return {left,left->val};
        }

        if(left->val != right->val){
            left->isLeaf = false;

            left->topLeft = intersect(left->topLeft, right->topLeft);
            left->topRight = intersect(left->topRight, right->topRight);
            left->bottomLeft= intersect(left->bottomLeft, right->bottomLeft);
            left->bottomRight = intersect(left->bottomRight, right->bottomRight);
            return left;
        }

        left->isLeaf = true;
        left->bottomLeft =nullptr;
        left->bottomRight=nullptr;
        left->topLeft=nullptr;
        left->topRight=nullptr;
        return left;

    }
};
