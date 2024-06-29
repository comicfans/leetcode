#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#ifdef LEETCODE
#include "../parse.h"

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
#endif

class Solution {
public:
  vector<int> postorder(Node *root) {
    vector<int> ret;
    rec(root, ret);
    return ret;
  }
  void rec(Node *root, vector<int> &ret) {
    if (!root) {
      return;
    }
    for (auto v : root->children) {
      rec(v, ret);
    }
    ret.push_back(root->val);
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
