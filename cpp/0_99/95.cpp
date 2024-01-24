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

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {

        vector<TreeNode*> ret;

        return gen(1, n);


    }

    vector<TreeNode*> gen(int minInc,int maxInc){


        vector<TreeNode*> ret;
        for(int i = minInc;i <= maxInc;++i){


            auto left= gen(minInc, i-1);
            auto right = gen(i+1, maxInc);

            for(auto leftT: left){
                for(auto rightT: right){
                    TreeNode* newRoot = new TreeNode(i,leftT,rightT);
                    ret.push_back(newRoot);
                }
            }

        }
        if(ret.empty()){
            return {nullptr};
        }

        return ret;
    }
};
