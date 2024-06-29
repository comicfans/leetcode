#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#ifdef LEETCODE
#include "../parse.h"
#endif

// jj

class Solution {
public:
  string tree2str(TreeNode *root) {

    string ret;
    rec(root, ret);
    return ret;
  }
  void rec(TreeNode *root, string &ret) {

    if (!root) {
      return;
    }
    ret += to_string(root->val);

        if(!root->left && !root->right){
            return;
        }


    ret.push_back('(');
    rec(root->left, ret);
    ret.push_back(')');

    if (root->right) {
      ret.push_back('(');
      rec(root->right, ret);
      ret.push_back(')');
    }
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
