#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

#ifdef LEETCODE
#include "../parse.h"
#endif

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        map<int,int> valueCount;

        rec(root, valueCount);

        vector<pair<int,int>> vec(valueCount.begin(), valueCount.end());
        sort(vec.begin(),vec.end(), [](const auto& lhs, const auto& rhs){
            return lhs.second > rhs.second;
        });

        if(vec.empty()){
            return {};
        }
        
        int maxCount = vec.front().second;
        vector<int> ret;
        for(auto kv: vec){
            if(kv.second != maxCount){
                break;
            }
            ret.push_back(kv.first);
        }
        return ret;
    }

    int rec(TreeNode* root, map<int,int>& valueCount){

        if(!root){
            return 0;
        }

        int leftSum = rec(root->left, valueCount);
        int rightSum = rec(root->right, valueCount);
        int thisSum = leftSum + rightSum + root->val;

        valueCount[thisSum]++;

        return thisSum;

    }
};
