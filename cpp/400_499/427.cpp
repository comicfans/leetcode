#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#ifdef LEETCODE
#include "../parse.h"
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
#endif

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return rec(grid, 0,0, grid.size());
    }

    Node* rec(const vector<vector<int>>& grid,int y, int x, int size){

        if(size == 0){
            return nullptr;
        }

        if(size == 1){
            return new Node(grid[y][x], true);
        }

        Node* ret = new Node();

        ret->topLeft = rec(grid,y,x, size / 2);
        ret->topRight = rec(grid,y,x + size / 2, size / 2);
        ret->bottomLeft = rec(grid, y+ size/2, x, size/2);
        ret->bottomRight = rec(grid, y+ size/2, x + size/2, size/2);

        if(ret->topLeft && 
            ret->topLeft->val == ret->topRight->val && 
            ret->topLeft->val == ret->bottomLeft->val &&
            ret->topLeft->val == ret->bottomRight->val &&
            ret->topLeft->isLeaf &&
            ret->topRight->isLeaf &&
            ret->bottomLeft->isLeaf &&
            ret->bottomRight->isLeaf){

            ret->val = ret->topLeft->val;
            delete ret->topLeft;
            delete ret->topRight;
            delete ret->bottomLeft;
            delete ret->bottomRight;

            ret->topLeft = nullptr;
            ret->topRight = nullptr;
            ret->bottomLeft = nullptr;
            ret->bottomRight = nullptr;
            ret->isLeaf = true;
        }

        return ret;


    }
};

int main(){
    Solution s;
    {
        VVI mat= {{1,1,0,0},
                  {0,0,1,1},
                  {1,1,0,0},
                  {0,0,1,1}};
        auto res = s.construct(mat);
        int a = 3;
    }
}
